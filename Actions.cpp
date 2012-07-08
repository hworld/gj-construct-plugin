// Include StdAfx
#include "StdAfx.h"

//////////////////////////////////////////////////////////////////////////////////
// Actions
//////////////////////////////////////////////////////////////////////////////////

long ExtObject::aSetGameID( LPVAL params )
{

	// Get the Game ID.
	api.SetGameID( params[0].GetInt() );

	return 0;

}

long ExtObject::aSetGamePrivateKey( LPVAL params )
{

	// Get the game's private key.
	api.SetGamePrivateKey( CStdString( params[0].GetString() ) );

	return 0;

}

long ExtObject::aSetUsername( LPVAL params )
{

	// Set the username.
	api.SetUsername( CStdString( params[0].GetString() ) );

	return 0;

}

long ExtObject::aSetUserToken( LPVAL params )
{

	// Get the user token.
	api.SetUserToken( CStdString( params[0].GetString() ) );

	return 0;

}

long ExtObject::aAddAchievedTrophy( LPVAL params )
{

	api.AddAchievedTrophy( params[0].GetInt() );

	return 0;

}

long ExtObject::aSetGameStorageItem( LPVAL params )
{

	DataStoreItem item = api.GetDataStoreItem( DataStoreItem::GAME, CStdString( params[0].GetString() ) );

	api.SetDataStoreItem( item, CStdString( params[1].GetString() ) );

	return 0;

}

long ExtObject::aSetUserStorageItem( LPVAL params )
{

	DataStoreItem item = api.GetDataStoreItem( DataStoreItem::USER, CStdString( params[0].GetString() ) );

	api.SetDataStoreItem( item, CStdString( params[1].GetString() ) );

	return 0;

}

long ExtObject::aRemoveGameStorageItem( LPVAL params )
{

	DataStoreItem item = api.GetDataStoreItem( DataStoreItem::GAME, CStdString( params[0].GetString() ) );

	api.RemoveDataStoreItem( item );

	return 0;

}

long ExtObject::aRemoveUserStorageItem( LPVAL params )
{

	DataStoreItem item = api.GetDataStoreItem( DataStoreItem::USER, CStdString( params[0].GetString() ) );

	api.RemoveDataStoreItem( item );

	return 0;

}

long ExtObject::aLoadScores( LPVAL params )
{

	int paramVal = params[0].GetInt();
	bool onlyUser = false;

	if ( paramVal == 1 )
		onlyUser = true;

	int tableId = params[1].GetInt();
	int limit = params[2].GetInt();

	m_Scores = api.GetScores( tableId, onlyUser, limit );

	return 0;

}

long ExtObject::aAddScore( LPVAL params )
{

	CString scoreString = params[0].GetString();
	int scoreSort = params[1].GetInt();
	CString extraData = params[2].GetString();
	CString guestName = params[3].GetString();
	int tableId = params[4].GetInt();

	api.AddScore( CStdString( scoreString ), scoreSort, tableId, CStdString( extraData ), CStdString( guestName ) );

	return 0;

}