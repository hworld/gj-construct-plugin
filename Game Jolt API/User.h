#ifndef USER_H
#define USER_H

using namespace std;

class GameJoltAPI;

class User
{

public:

	User();

	bool Initialize( GameJoltAPI *api );

	CStdString GetUsername();
	bool SetUsername( CStdString username );

	CStdString GetUserToken();
	bool SetUserToken( CStdString userToken );

private:

	bool m_Initialized;

	GameJoltAPI *m_pAPI;

	CStdString m_Username;
	CStdString m_UserToken;

};

#endif