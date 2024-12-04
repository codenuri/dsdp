#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:

	void draw() { std::cout << "Draw " << image_url << std::endl; }

	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url); 

		if (it == image_map.end()) 
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = it->second; 
		return img;
	}

	inline static std::map<std::string, Image*> image_map;
};



int main()
{
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}



