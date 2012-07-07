#ifndef DATASTOREITEM_H
#define DATASTOREITEM_H

using namespace std;

class GameJoltAPI;

class DataStoreItem
{

public:

	enum Type
	{
		GAME,
		USER
	};

	DataStoreItem();

	bool Initialize( GameJoltAPI *api, DataStoreItem::Type type, CStdString key );

	DataStoreItem::Type GetType();
	CStdString GetKey();
	CStdString GetData();

private:

	bool m_Initialized;

	GameJoltAPI *m_pAPI;

	DataStoreItem::Type m_Type;
	CStdString m_Key;
	CStdString m_Data;

};

#endif