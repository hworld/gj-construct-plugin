#ifndef TROPHY_H
#define TROPHY_H

using namespace std;

class GameJoltAPI;

class Trophy
{

public:

	Trophy();

	bool Initialize( GameJoltAPI *api, map<CStdString, CStdString> trophyInfo );

	int GetID();
	CStdString GetTitle();
	CStdString GetDescription();
	CStdString GetDifficulty();
	CStdString GetAchievedDate();
	CStdString GetImageURL();
	bool IsAchieved();

private:

	// Utility functions.
	bool GetTrophyInfo( map<CStdString, CStdString> &trophyInfo );

	bool m_Initialized;

	GameJoltAPI *m_pAPI;

	int m_ID;
	CStdString m_Title;
	CStdString m_Description;
	CStdString m_Difficulty;
	CStdString m_ImageURL;

};

#endif