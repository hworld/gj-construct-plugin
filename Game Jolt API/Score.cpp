#include "StdAfx.h"
#include "Score.h"


Score::Score():
	m_Initialized( false ),
	m_Score( _T("") ),
	m_Sort( 0 ),
	m_ExtraData( _T("") ),
	m_User( _T("") ),
	m_UserID( 0 ),
	m_Guest( _T("") ),
	m_StoredDate( _T("") )
{

	/* Nothing */

}


bool Score::Initialize( GameJoltAPI *api, map<CStdString, CStdString> scoreInfo )
{

	m_pAPI = api;

	m_Score = scoreInfo["score"];
	m_Sort = atoi( CStdStringA( scoreInfo["sort"] ) );
	m_ExtraData = scoreInfo["extra_data"];
	m_User = scoreInfo["user"];
	m_UserID = atoi( CStdStringA( scoreInfo["user_id"] ) );
	m_Guest = scoreInfo["guest"];
	m_StoredDate = scoreInfo["stored"];

	m_Initialized = true;

	return true;

}


CStdString Score::GetScore()
{

	return m_Score;

}


int Score::GetSort()
{

	return m_Sort;

}


CStdString Score::GetExtraData()
{

	return m_ExtraData;

}


CStdString Score::GetUser()
{

	return m_User;

}


int Score::GetUserID()
{

	return m_UserID;

}


CStdString Score::GetGuest()
{

	return m_Guest;

}


CStdString Score::GetStoredDate()
{

	return m_StoredDate;

}