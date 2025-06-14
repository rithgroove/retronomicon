#include "retronomicon/lib/asset/asset_manager.h"

/**
 * @brief This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
	/**
	 * @brief Constructor using renderer
	 * 
	 * @param renderer a renderer that will be passed to any object loaded by this asset manager.
	 */
    AssetManager::AssetManager(SDL_Renderer* renderer){
    	m_renderer = renderer; //set renderer
    }
	
	/**
	 * @brief The destructor of the object, used to destroy maps using unsorted_map.clear() function
	 */
    AssetManager::~AssetManager(){
    	m_imageMap.clear(); //clear image map
    	m_fontMap.clear(); //clear font map
    }
	
    /**
     * @brief A method to load image from drive and put it in local map (m_imageMap) 
     * caveats:
     * - Currently only accept PNG.
     * - will return nullptr if not found 
     * - will return nullptr if name exist but have different filepath
     * - will load the image from drive if not exist
     * - if exists in cache will use the one preloaded before
     * 
     * @param imagePath the path to the image
     * @param name the name or key for the image so we can request it again in the future
     * @param forceReplace set true if you want to load the image from the drive again
     * @return the image
     */
	RawImage* AssetManager::loadImage(const string& imagePath,const string& name, bool forceReplace){
		//declare
    	RawImage* image = nullptr;

    	//get from cache first
	    try{
	    	image = this->getImage(name);
	    	if (imagePath.compare(image->getPath()) != 0 && !forceReplace){
	    		return nullptr;
	    	}
	    } catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl; 
	    }

	    //return if exist in cache
	    if (image){
	    	if (!forceReplace){
	    		this->removeImage(name);
	    	}else{
	    		return image;
	    	}
	    }

	    // if not exists in cache, try load from drive
    	try {
	  		image = new RawImage(imagePath,name,m_renderer); //try to create image
	  		m_imageMap[name] = image;	    		
    		cout <<"Load " << name << " from memory" <<endl;
    	}catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl; 
	    } 

	    // return the result
	  	return image;
  	}

    /**
     * @brief  A method to get the loaded image
     *
     * @param name the name/key for the image
     * @return the instance of RawImage that represent the image
     */
	RawImage* AssetManager::getImage(const string& name){

    	cout << "debug 1 = "<<name << endl;
    	auto it = m_imageMap.find(name);
        if (it != m_imageMap.end()) {
            return it->second;
        } else {
			throw std::runtime_error("Image not found for key: " + name);
        }
    }
    
    /**
     * @brief A method to remove the loaded image from memory
     *
     * @param name the name/key for the image
     * @return return true if success, return false if failed
     */
    bool AssetManager::removeImage(const string& name){
    	RawImage* image =this->getImage(name);
    	if (image){
    		m_imageMap.erase(image->getName());
       	}else{
	        cerr << "Error: File with name:  " << name << " not found in memory "<< endl;
    		return false;
    	}
    	return true;

    }
	
    /**
     * @brief A method to load font from drive and put it in local map (m_fontMap)
     * caveats:
     * - Currently only accept TTF.
     * - each size needs to be initiated differently (so Arial 16 and Arial 18 will be initiated as 2 different font)
     * - will return nullptr if not found 
     * - will return nullptr if name exist but have different filepath
     * - will load the front from drive if not exist
     * - if exists in cache will use the one preloaded before
     * 
     * @param imagePath the path to the font
     * @param name the name or key for the font so we can request it again in the future
     * @param size the size for the font so we can request it again in the future
     * @param forceReplace set true if you want to load the image from the drive again
     * @return return true if success, return false if failed
     */
    Font * AssetManager::loadFont(const string& fontPath,const string& name, int size, bool forceReplace){
    	//setup keys
	    string tempName = name + "-" + to_string(size);
		Font *font = nullptr;

		// load from existing
	    try{
	    	font = this->getFont(name,size);
	    	if (fontPath.compare(font->getPath()) != 0 && !forceReplace){
	    		return nullptr;
	    	}
	    } catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl;
	    } 

	    // if not empty return font
	    if (font){
	    	if (!forceReplace){
	    		this->removeFont(name,size);
	    	}else{
		    	return font;
	    	}
	    }

	    // load from memory
	    try{
		    font = new Font(fontPath, tempName,size,m_renderer); 
	  		m_fontMap[tempName] = font;
    		cout <<"Load " << name << " from memory" <<endl;
	    } catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl;
	    }
  		return font;
  	}

    /**
     * @brief A method to get the font from memory
     *
     * @param name the name/key for the font
     * @param size the size of the font
     */
	Font* AssetManager::getFont(const string& name, int size){

    	string tempName = name + "-" + to_string(size);
    	cout << "debug 1 = "<< tempName << endl;
    	auto it = m_fontMap.find(tempName);
        if (it != m_fontMap.end()) {
            return it->second;
        } else {
			throw std::runtime_error("Image not found for key: " + tempName);
        }
    }

    /**
     * @brief A method to remove the loaded font from memory
     *
     * @param name the name/key for the font
     * @param size the size of the font
     * @return return true if success, return false if failed
     */
    bool AssetManager::removeFont(const string& name, int size){
    	string tempName = name + "-" + to_string(size);
    	RawImage* image =this->getImage(tempName);
    	if (image){
    		m_imageMap.erase(image->getName());
    	}else{
	        cerr << "Error: File with name:  " << name << " not found in memory "<< endl;
    		return false;
    	}
    	return true;

    }
} // namespace Retronomicon