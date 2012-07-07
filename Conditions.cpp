// Include StdAfx
#include "StdAfx.h"

//////////////////////////////////////////////////////////////////////////////////
// Conditions
//////////////////////////////////////////////////////////////////////////////////

long ExtObject::cIsValidUser( LPVAL params )
{

	return api.AuthUser();

}

long ExtObject::cIsTrophyAchieved( LPVAL params )
{

	return api.GetTrophy( params[0].GetInt() ).IsAchieved();

}

long ExtObject::cIsGuestScore( LPVAL params )
{

	int index = params[0].GetInt();

	if ( index >= m_Scores.size() )
		return false;

	if ( m_Scores[index].GetGuest() == _T("") )
		return true;

	return false;

}

long ExtObject::cIsGameStorageItemSet( LPVAL params )
{

	if ( api.GetDataStoreItem( DataStoreItem::GAME, CStdString( params[0].GetString() ) ).GetData() != _T("") )
		return true;

	return false;

}

long ExtObject::cIsUserStorageItemSet( LPVAL params )
{

	if ( api.GetDataStoreItem( DataStoreItem::USER, CStdString( params[0].GetString() ) ).GetData() != _T("") )
		return true;

	return false;

}