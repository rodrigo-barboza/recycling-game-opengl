#include <cstring>
#include <string>

class Object {
	private: 
		char object_name[50];
		std::string object_path;
		char object_category[50];
		int points;
	public: 
		GLuint texture;
		
		Object(char object_name[], std::string object_path, char object_category[], int points) {
			strcpy(this->object_name, object_name);
			this->object_path = object_path;
			strcpy(this->object_category, object_category);
			this->points = points;
		}

		char* getObjectName() {
			return object_name;
		}

		std::string getObjectPath() {
			return object_path;
		}

		char* getObjectCategory() {
			return object_category;
		}

		int getObjectPoint() {
			return points;
		}
};
