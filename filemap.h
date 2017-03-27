#pragma once

#ifndef __INCLUDE_FILE_MAP_H__
#define __INCLUDE_FILE_MAP_H__


class CFileMap
{
public:
	CFileMap();
	~CFileMap();
public:
	int OpenMap(const char* pFileName,int iMapLen,int iOffset);
	int Read(char *pBuf,int iReadLen);
	int Write(const char *pBuf,int iWriteLen);
	void CloseMap();
private:
	void* 	m_pStart; 		//base address
	int 	m_fd;			//file descriptor of FileName
	int		m_iMapLength; 	//mapping length
	int		m_iOperatorPos; //current operator position
};

#endif //__INCLUDE_FILE_MAP_H__