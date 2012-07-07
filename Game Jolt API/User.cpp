#include "StdAfx.h"
#include "User.h"


bool User::Initialize( GameJoltAPI *api )
{

	m_pAPI = api;

	return true;

}


CStdString User::GetUsername()
{

	return m_Username;

}


bool User::SetUsername( CStdString username )
{

	m_Username = username;

	return true;

}


CStdString User::GetUserToken()
{

	return m_UserToken;

}


bool User::SetUserToken( CStdString userToken )
{

	m_UserToken = userToken;

	return true;

}