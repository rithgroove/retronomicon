namespace retronomicon::lib::asset{
	/*************************************************************************************************
    * Constructor initialize the maps	    	
    *************************************************************************************************/
    AssetManager::AssetManager(){}
	
	/*************************************************************************************************
    * Destructor initialize the maps	    	
    *************************************************************************************************/
    // AssetManager::~AssetManager(){}
	
    bool loadImage( const std::string& imagePath, const std::string& name){
	    try{
	  		RawImage* image=  RawImage(imagePath,name);
	  		m_imageMap[image.getName] = image;
	  		m_imageFileNameMap[image.getPath] = image;	    	
	    } catch (const std::runtime_error& error) {
	        std::cerr << "Error: " << error.what() << std::endl;
	        return FALSE;
	    } catch (const std::exception& error) {
	        std::cerr << "Error: " << error.what() << std::endl;
	        return FALSE;
	    }
  		return TRUE;
  	}

	RawImage* getImage(const std::string& name){
    	RawImage* temp = m_imageMap[name];
    	if (temp != NULL){
    		temp = m_imageFileNameMap[name];
    	}
    	return temp;
    }

    bool removeImage(const std::string& name){
    	RawImage* image = nullptr;
    	try{
    		image = this.getImage(name);
    	}
    	if (!temp){
	        std::cerr << "Error: File with name:  " << name << " not found in memory "<< std::endl;
    		return FALSE;
    	}else{
    		m_imageMap.erase(image.getName());
    		m_imageFileNameMap.erase(image.getPath());
    	}
    	return TRUE;

    }

} // namespace Retronomicon