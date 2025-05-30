#include "retronomicon/lib/asset/asset_manager.h"

using namespace std;
namespace retronomicon::lib::asset{
	/*************************************************************************************************
    * Constructor initialize the maps	    	
    *************************************************************************************************/
    AssetManager::AssetManager(SDL_Renderer* renderer){
    	m_renderer = renderer;
    }
	
	/*************************************************************************************************
    * Destructor initialize the maps	    	
    *************************************************************************************************/
    // AssetManager::~AssetManager(){}
	
    bool AssetManager::loadImage(string imagePath,string name){
	    try{
	  		RawImage* image= new RawImage(imagePath,name,m_renderer);
	  		m_imageMap[image->getName()] = image;
	  		m_imageFileNameMap[image->getPath()] = image;	    	
	    } catch (const runtime_error& error) {
	        cerr << "Error: " << error.what() << endl;
	        return false;
	    } catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl;
	        return false;
	    }
  		return true;
  	}

	RawImage* AssetManager::getImage(string name){
    	RawImage* temp = m_imageMap[name];
    	if (temp != NULL){
    		temp = m_imageFileNameMap[name];
    	}
    	return temp;
    }

    bool AssetManager::removeImage(string name){
    	RawImage* image =this->getImage(name);
    	if (image){
    		m_imageMap.erase(image->getName());
    		m_imageFileNameMap.erase(image->getPath());
    	}else{
	        cerr << "Error: File with name:  " << name << " not found in memory "<< endl;
    		return false;
    	}
    	return true;

    }

} // namespace Retronomicon