 
class FilesManager
{
public:
	
	bool HadAsset();
	bool HadConfig();
	bool HadSave();
	bool LoadConfig();

	struct DisplayConfig
	{
		int Width;
		int Height;
		int FontSize;
	};
	DisplayConfig displayconfig;
};

