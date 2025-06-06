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
			throw std::runtime_error("Image not found for key: " + name);
        }
    }

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

	/*************************************************************************************************
    * Destructor initialize the maps	    	
    *************************************************************************************************/
    // AssetManager::~AssetManager(){}
	
    bool AssetManager::loadFont(const string& fontPath,const string& name, int size){
	    try{
	    	string tempName = name + "-" + to_string(size);
		    Font *font = new Font(fontPath, tempName,size,m_renderer); 
	  		m_fontMap[tempName] = font;
	    } catch (const runtime_error& error) {
	        cerr << "Error: " << error.what() << endl;
	        return false;
	    } catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl;
	        return false;
	    }
  		return true;
  	}

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