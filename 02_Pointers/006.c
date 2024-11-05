enum DataType
{
	INTEGER,
	FLOAT,
	POINTER,
	NONE
};

struct DataHolder
{
	enum DataType type;
	union
	{
		int i;
		float f;
		void *p;
	} data;
};

void set_data(struct DataHolder *holder, enum DataType type, void *value);
void *get_data(struct DataHolder *holder, enum DataType *type);
