// Include StdAfx.h
#include "StdAfx.h"

#ifdef RUN_ONLY

/////////////////////////////
// RUNTIME serialization
void ExtObject::Serialize(bin& ar)
{

	int gameID;
	CString gamePrivateKey;
	CString username;
	CString userToken;

	if (ar.loading) 
	{

		ar >> gameID >> gamePrivateKey >> username >> userToken >> m_LoadScoresCount;

		api.SetGameID( gameID );
		api.SetGamePrivateKey( CStdString( gamePrivateKey ) );
		api.SetUsername( CStdString( username ) );
		api.SetUserToken( CStdString( userToken ) );

	}
	else 
	{

		ar << api.GetGameID() << CString( api.GetGamePrivateKey() ) << CString( api.GetUsername() ) << CString( api.GetUserToken() ) << m_LoadScoresCount;

	}
}

#else // RUN_ONLY

/////////////////////////////
// EDITTIME serialization
// Save and load all your object's edittime data here.
// If you change the serialization format after plugin release, change 'Version' and check it while loading.
// You can then use the old serialization routine if 'Version' is still 1, and set new features to their defaults.
// You never need to check 'Version' while saving.
void EditExt::Serialize(bin& ar)
{
	int Version = 1;
	SerializeVersion(ar, Version);

	if (ar.loading) 
	{

		ar >> m_GameID >> m_GamePrivateKey >> m_LoadScoresCount;

	}
	else 
	{
		
		ar << m_GameID << m_GamePrivateKey << m_LoadScoresCount;

	}
}

#endif // RUN_ONLY