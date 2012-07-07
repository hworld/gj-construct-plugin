#include "StdAfx.h"
#include "Trophy.h"

CTrophy::CTrophy( map<CString,CString> trophyInfo )
{
	
	trophyInfo["id"].Format( "%d", m_ID );
	m_Title = trophyInfo["title"];
	m_Description = trophyInfo["description"];
	m_Difficulty = trophyInfo["difficulty"];
	m_AchievedDate = trophyInfo["achieved"];
	
}