#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h> 

#include "filemap.h"

CFileMap::CFileMap()
{
	m_pStart = NULL;
	m_iMapLength = 0;
	m_iOperatorPos = 0;
	m_fd = -1;
}

CFileMap::~CFileMap()
{
	CloseMap();
}

int CFileMap::OpenMap(const char* pFileName,int iMapLen,int iOffset)
{
	//check parameter
	if(NULL == pFileName || iMapLen <= 0 )
	{
		return -1;
	}
	//safe open file mapping
	CloseMap();
	//open file in order to save file descriptor
	m_fd = open(pFileName,O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	if(-1 == m_fd)
	{
		return  -1;
	}
	
	//offset should be a multiple of the page size
	//set offset size
	int pagesize = getpagesize(); //4096 4k
	int mutilple = iOffset/pagesize;
	iOffset = mutilple*pagesize;
	
	//begin mapping
	m_pStart = mmap(NULL,iMapLen,PROT_WRITE |PROT_READ,
					MAP_SHARED, //MAP_SHARED: writing to the file;
					m_fd,iOffset);
		/*
		MAP_FIXED:		if start is NULL or invalid then mapping fail;
		MAP_SHARED:		writing to the file;
		MAP_PRIVATE:	can not writing to the file;
		*/
	if(MAP_FAILED == m_pStart)//On error, the value MAP_FAILED is returned
	{
		close(m_fd);
		m_fd = -1;
		return -1;
	}
	//save parameter
	m_iMapLength = iMapLen;
	
	return iMapLen;
}

int CFileMap::Read(char *pBuf,int iReadLen)
{
	//check parameter
	if(NULL == pBuf || iReadLen <= 0)
	{
		return -1;
	}
	//check current position
	if(m_iOperatorPos == m_iMapLength)
	{
		//caller should remap
		return -1;
	}
	if((m_iMapLength - m_iOperatorPos) < iReadLen)
	{
		//mapping m_iMapLength - m_iOperatorPos
		memcpy(pBuf,((char*)m_pStart+m_iOperatorPos),
			m_iMapLength - m_iOperatorPos);
		//file mapped content over
		m_iOperatorPos = m_iMapLength;
		return m_iMapLength - m_iOperatorPos;
	}
	memcpy(pBuf,((char*)m_pStart+m_iOperatorPos),
		iReadLen);
	//move current position
	m_iOperatorPos+=iReadLen;
	
	return iReadLen;
}

int CFileMap::Write(const char *pBuf,int iWriteLen)
{
	//check parameter
	if(NULL == pBuf || 0 == iWriteLen)
	{
		return -1;
	}
	
	//check current position
	if(m_iOperatorPos == m_iMapLength)
	{
		//caller should remap
		return -1;
	}
	if((m_iMapLength - m_iOperatorPos) < iWriteLen)
	{
		//mapping m_iMapLength - m_iOperatorPos
		memcpy(((char*)m_pStart+m_iOperatorPos),pBuf,
			m_iMapLength - m_iOperatorPos);
		//file mapped content over
		m_iOperatorPos = m_iMapLength;
		return m_iMapLength - m_iOperatorPos;
	}
	memcpy(((char*)m_pStart+m_iOperatorPos),pBuf,
		iWriteLen);
	//move current position
	m_iOperatorPos+=iWriteLen;
	
	return iWriteLen;
}

void CFileMap::CloseMap()
{
	if(m_pStart)
	{
		munmap(m_pStart,m_iMapLength);
		m_pStart = NULL;
		m_iMapLength = 0;
	}
	if(m_fd)
	{
		close(m_fd);
		m_fd = -1;
	}
	m_iOperatorPos = 0;	
}




