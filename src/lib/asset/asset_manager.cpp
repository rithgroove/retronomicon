#include "retronomicon/lib/asset/asset_manager.h"

using namespace std;
namespace retronomicon::lib::asset{

	/*************************************************************************************************
    * Constructor initialize the maps	    	
    *************************************************************************************************/
    AssetManager::AssetManager(SDL_Renderer* renderer){
    	m_renderer = renderer; //set renderer
    }
	
	/*************************************************************************************************
    * Destructor initialize the maps	    	
    *************************************************************************************************/
    AssetManager::~AssetManager(){
    	m_imageMap.clear(); //clear image map
    	m_fontMap.clear() //clear font map
    }
	
	/*************************************************************************************************
    * Load image and store it to memory
    * 
    * return true if successfull
    * return false if fails
    *************************************************************************************************/
    bool AssetManager::loadImage(const string& imagePath,const string& name){
	    try{
	  		RawImage* image= new RawImage(imagePath,name,m_renderer); //try to create image
	  		m_imageMap[name] = image;
	    } catch (const runtime_error& error) {
	        cerr << "Error: " << error.what() << endl; // if runtime error catch it
	        return false;
	    } catch (const exception& error) {
	        cerr << "Error: " << error.what() << endl; // if other exception error catch it
	        return false;
	    }
  		return true;
  	}

	/*************************************************************************************************
    * get image by name(key) from memory
    *************************************************************************************************/
	RawImage* AssetManager::getImage(const string& name){

    	cout << "debug 1 = "<<name << endl;
    	auto it = m_imageMap.find(name);
        if (it != m_imageMap.end()) {
            return it->second;
        } else {
			throw std::runtime_error("Image not found for key: " + name);
        }
    }

	/*************************************************************************************************
    * remove image from memory
    *************************************************************************************************/
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
    * Load font and store it to memory
    * 
    * return true if successfull
    * return false if fails
    *************************************************************************************************/
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

	/*************************************************************************************************
    * get font by name(key) and size from memory
    *************************************************************************************************/
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

	/*************************************************************************************************
    * remove font from memory
    *************************************************************************************************/
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