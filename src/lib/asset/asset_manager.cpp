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
	
    bool AssetManager::loadImage(const string& imagePath,const string& name){
	    try{
	  		RawImage* image= new RawImage(imagePath,name,m_renderer);
	  		m_imageMap[name] = image;
	  		m_imageFileNameMap[imagePath] = image;
	    } catch (const runtime_error& error) {
	        cerr << "Error: " << error.what() << endl;
	        return false;
	    } catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl;
	        return false;
	    }
  		return true;
  	}

	RawImage* AssetManager::getImage(const string& name){

    	cout << "debug 1 = "<<name << endl;
    	auto it = m_imageMap.find(name);
        if (it != m_imageMap.end()) {
            return it->second;
        } else {
	    	auto it = m_imageFileNameMap.find(name);
	        if (it != m_imageFileNameMap.end()) {
	            return it->second;
	        } else {
				throw std::runtime_error("Image not found for key: " + name);
	        }

        }
    }

    bool AssetManager::removeImage(const string& name){
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