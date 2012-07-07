// Include StdAfx
#include "StdAfx.h"

//////////////////////////////////////////////////////////////////////////////////
// Built-in expressions
//////////////////////////////////////////////////////////////////////////////////

// Return the Default Value.  This is the value to be returned if your object name
// is used without an expression name, eg. in "Counter + 1".
// Parameters can be passed, eg. MyObject(3,7).  You can check ExpReturn::Type() or GetNumParams() to check for overloads.
long ExtObject::ReturnDefaultValue(LPVAL theParams, ExpReturn& ret)
{
	return ret = 0;
}

// Called for undefined expression names, if your extension allows it.
// Eg: MyObject.UndefinedExpression(3,4,5) calls this routine with
// "UndefinedExpression" as the expression name.  OF_UNDEFINEDEXPRESSIONS must be specified in Main.h.
long ExtObject::ReturnUndefinedExpression(CString& expName, LPVAL theParams, ExpReturn& ret)
{
	return ret = 0;
}

//////////////////////////////////////////////////////////////////////////////////
// Expressions
//////////////////////////////////////////////////////////////////////////////////

long ExtObject::eGetGameID( LPVAL params, ExpReturn &ret )
{

	return ret = api.GetGameID();

}

long ExtObject::eGetGamePrivateKey( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetGamePrivateKey() );

}

long ExtObject::eGetUsername( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetUsername() );

}

long ExtObject::eGetUserToken( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetUserToken() );

}

long ExtObject::eGetErrorMessage( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetErrorMessage() );

}

long ExtObject::eGetTrophyTitle( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetTrophy( params[0].GetInt() ).GetTitle() );

}

long ExtObject::eGetTrophyDescription( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetTrophy( params[0].GetInt() ).GetDescription() );

}

long ExtObject::eGetTrophyDifficulty( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetTrophy( params[0].GetInt() ).GetDifficulty() );

}

long ExtObject::eGetTrophyAchievedDate( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetTrophy( params[0].GetInt() ).GetAchievedDate() );

}

long ExtObject::eGetGameStorageData( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetDataStoreItem( DataStoreItem::GAME, CStdString( params[0].GetString() ) ).GetData() );

}

long ExtObject::eGetUserStorageData( LPVAL params, ExpReturn &ret )
{

	return ret.ReturnString( pRuntime, api.GetDataStoreItem( DataStoreItem::USER, CStdString( params[0].GetString() ) ).GetData() );

}

long ExtObject::eGetScoresCount( LPVAL params, ExpReturn &ret )
{

	return ret = m_Scores.size();

}

long ExtObject::eGetScoreString( LPVAL params, ExpReturn &ret )
{

	int index = params[0].GetInt();

	if ( index >= m_Scores.size() )
		return ret.ReturnString( pRuntime, _T("" ) );

	return ret.ReturnString( pRuntime, m_Scores[index].GetScore() );

}

long ExtObject::eGetScoreSort( LPVAL params, ExpReturn &ret )
{

	int index = params[0].GetInt();

	if ( index >= m_Scores.size() )
		return ret = 0;

	return ret = m_Scores[index].GetSort();

}

long ExtObject::eGetScoreExtraData( LPVAL params, ExpReturn &ret )
{

	int index = params[0].GetInt();

	if ( index >= m_Scores.size() )
		return ret.ReturnString( pRuntime, _T("" ) );

	return ret.ReturnString( pRuntime, m_Scores[index].GetExtraData() );

}

long ExtObject::eGetScoreUser( LPVAL params, ExpReturn &ret )
{

	int index = params[0].GetInt();

	if ( index >= m_Scores.size() )
		return ret.ReturnString( pRuntime, _T("" ) );

	if ( m_Scores[index].GetUser() != _T("") )
		return ret.ReturnString( pRuntime, m_Scores[index].GetUser() );
	else
		return ret.ReturnString( pRuntime, m_Scores[index].GetGuest() );

}

long ExtObject::eGetScoreUserID( LPVAL params, ExpReturn &ret )
{

	int index = params[0].GetInt();

	if ( index >= m_Scores.size() )
		return ret = 0;

	return ret = m_Scores[index].GetUserID();

}

long ExtObject::eGetScoreStoredDate( LPVAL params, ExpReturn &ret )
{

	int index = params[0].GetInt();

	if ( index >= m_Scores.size() )
		return ret.ReturnString( pRuntime, _T("" ) );

	return ret.ReturnString( pRuntime, m_Scores[index].GetStoredDate() );

}