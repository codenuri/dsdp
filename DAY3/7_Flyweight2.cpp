﻿// 5_Flyweight - 167
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

	// 자신의 객체를 만드는 static 멤버 함수
	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url); // map 에서 먼저 검색

		if (it == image_map.end()) // 없을때
		{
			img = new Image(url);
		}
		else
			img = it->second; // map 의 반복자는 pair 인데
							  // second 가 value(Image*) 입니다.

		return img;
	}

	static std::map<std::string, Image*> image_map;
};

std::map<std::string, Image*> Image::image_map;


int main()
{
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}


