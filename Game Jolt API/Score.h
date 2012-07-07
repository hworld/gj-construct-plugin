#ifndef SCORE_H
#define SCORE_H

using namespace std;

class GameJoltAPI;

class Score
{

public:

	Score();

	bool Initialize( GameJoltAPI *api, map<CStdString, CStdString> scoreInfo );

	CStdString GetScore();
	int GetSort();
	CStdString GetExtraData();
	CStdString GetUser();
	int GetUserID();
	CStdString GetGuest();
	CStdString GetStoredDate();

private:

	bool m_Initialized;

	GameJoltAPI *m_pAPI;

	CStdString m_Score;
	int m_Sort;
	CStdString m_ExtraData;
	CStdString m_User;
	int m_UserID;
	CStdString m_Guest;
	CStdString m_StoredDate;

};

#endif