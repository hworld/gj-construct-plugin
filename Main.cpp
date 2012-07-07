// Include StdAfx
#include "StdAfx.h"
//#include "MD5.h"
//#include "Trophy.h"
/*
bool ExtObject::SendRequest( CString &sOutput, CString sURL )
{

	// The private key must be set to send a request.
	if ( m_GamePrivateKey == "" )
	{
		m_ErrorMessage += "(You must put in your game's private key before you can use any of the API functions.)";
		return false;
	}

	////////////////////////////////////
	// Let's form the URL first.

	sURL = ExtObject::GJAPI_ROOT + ExtObject::GJAPI_VERSION + sURL;
	CString sSignature( md5( (LPCTSTR)("http://" + ExtObject::GJAPI_SERVER + sURL + m_GamePrivateKey) ).c_str() );
	sURL += "&signature=" + sSignature;

	// Now let's build the request.
	BOOL bResults = FALSE;
	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = 0;
	HINTERNET hSession = NULL;
	HINTERNET hConnect = NULL;
	HINTERNET hRequest = NULL;

	hSession = WinHttpOpen
	(
		L"Game Jolt API Construct/1.0", 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 
		0
	);

	if ( hSession )
		hConnect = WinHttpConnect
		( 
			hSession, 
			CT2CW(ExtObject::GJAPI_SERVER),
			INTERNET_DEFAULT_PORT, 
			0
		);
	else
		m_ErrorMessage += "(Could not open HTTP session.)";

	if ( hConnect )
		hRequest = WinHttpOpenRequest
		( 
			hConnect,
			L"GET",
			CT2CW(sURL),
			NULL,
			WINHTTP_NO_REFERER,
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_REFRESH
		);
	else
		m_ErrorMessage += "(Could not connect to the HTTP session.)";

	if ( hRequest ) 
		bResults = WinHttpSendRequest
		( 
			hRequest,
			WINHTTP_NO_ADDITIONAL_HEADERS,
			0,
			WINHTTP_NO_REQUEST_DATA,
			0,
			0,
			0
		);
	else
		m_ErrorMessage += "(Could not set up the HTTP request.)";

	if ( bResults )
		bResults = WinHttpReceiveResponse( hRequest, NULL );
	else
		m_ErrorMessage += "(Could not send the HTTP request.)";

	// Keep checking for data until there is nothing left.
	if ( bResults )
	{
		do 
		{

			// Check for available data.
			dwSize = 0;
			WinHttpQueryDataAvailable( hRequest, &dwSize );

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize + 1];
			if( pszOutBuffer )
			{
				// Read the data.
				ZeroMemory( pszOutBuffer, dwSize + 1 );

				if ( WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, dwSize, &dwDownloaded ) )
					sOutput += pszOutBuffer;

				// Free the memory allocated to the buffer.
				delete [] pszOutBuffer;
			}

		} while( dwSize > 0 );
	}
	else
		m_ErrorMessage += "(Did not get a response from the server.)";

	if ( hRequest ) WinHttpCloseHandle( hRequest );
    if ( hConnect ) WinHttpCloseHandle( hConnect );
    if ( hSession ) WinHttpCloseHandle( hSession );

	return true;

}

bool ExtObject::ParseOutputString( CString inputString, vector<map<CString,CString>> &returnData )
{

	map<CString,CString> resourceData;
	vector<CString> parsedLines;
	vector<CString>::iterator it;
	CString curPiece;
	CString curKey = "";
	CString curValue = "";
	int curPos = 0;

	curPiece = inputString.Tokenize( _T("\n"), curPos );
	while ( curPiece != "" )
	{
		parsedLines.push_back( curPiece );
		curPiece = inputString.Tokenize( _T("\n"), curPos );
	}

	if ( parsedLines.size() == 0 )
	{
		m_ErrorMessage += "(Could not parse the response.)";
		return false;
	}

	for ( it = parsedLines.begin(); it < parsedLines.end(); it++ )
	{

		curPos = (*it).FindOneOf( ":" );
		curKey = (*it).Mid( 0, curPos );
		curValue = (*it).Mid( curPos + 2, (*it).GetLength() - curPos - 4 );
		
		// If this key is set, then we have looped and have a new resource.
		// Push the data and clear.
		if ( resourceData[curKey] != "" )
		{
			returnData.push_back( resourceData );
			resourceData.clear();
		}

		resourceData[curKey] = curValue;

	}

	// We do one final push.
	returnData.push_back( resourceData );

	if ( returnData.front()["success"] != "true" )
		m_ErrorMessage += "(" + returnData.front()["message"] + ")";

	// Return it.
	return true;

}

bool ExtObject::PopulateTrophyInfo()
{

	CString output;
	CString sGameID;
	vector<map<CString,CString>>::iterator it;
	vector<map<CString,CString>> parsedOutput;
	map<CString,CString> trophyInfo;
	bool retVal = true;
	int trophyID = 0;

	// Game ID must be set.
	if ( m_GameID <= 0 )
	{
		m_ErrorMessage += "(The game ID must be set.)";
		return false;
	}

	// Username must be set.
	if ( m_Username == "" )
	{
		m_ErrorMessage += "(The username must be set.)";
		return false;
	}

	// User token must be set.
	if ( m_UserToken == "" )
	{
		m_ErrorMessage += "(The user token must be set.)";
		return false;
	}

	// We must format the Game ID to a string.
	sGameID.Format( "%d", m_GameID );

	// Send the request.
	retVal = SendRequest( output, "/trophies/?game_id=" + sGameID + "&username=" + m_Username + "&user_token=" + m_UserToken );

	if ( !retVal )
	{
		m_ErrorMessage += "(Could not populate the trophy information.)";
		return false;
	}

	// Parse the output.
	retVal = ParseOutputString( output, parsedOutput );

	if ( !retVal )
	{
		m_ErrorMessage += "(Could not populate the trophy information.)";
		return false;
	}

	for ( it = parsedOutput.begin(); it != parsedOutput.end(); it++ )
	{
		trophyInfo = (*it);
		trophyID = atoi( trophyInfo["id"] );
		m_Trophies[trophyID] = new CTrophy( trophyInfo );
	}

	m_TrophiesPopulated = true;

	return true;

}
*/