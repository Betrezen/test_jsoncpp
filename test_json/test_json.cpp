// test_json.cpp : Defines the entry point for the console application.
// {\"file_path_TL\":\"F:\\@github\\MERA\\Debug\test_images\",\"file_path_FL_S\":\"F:\\@github\\MERA\\Debug\test_images\",\"file_path_FL_L\":\"F:\\@github\\MERA\\Debug\test_images\",\"file_name_TL\":\"E02_x1_y2_w0.tif\",\"file_name_FL_S\":\"E02_x1_y2_w1.tif\",\"file_name_FL_L\":\"E02_x1_y2_w2.tif\",\"processing_time\":312,\"beads\":[{\"bead_id\": 0,   \"bead_code\": 2340,   \"mirror\":1,   \"bead_area_count\":42,   \"target_area_count\":13,   \"bead_area\": [     {\"x\":517,\"y\":1,\"l\":2},	 {\"y\":2, \"x\":515, \"l\":4},	 {\"y\":3, \"x\":514, \"l\":6},	 {\"y\":4, \"x\":513, \"l\":8},	 {\"y\":5, \"x\":512, \"l\":10},	 {\"y\":6, \"x\":511, \"l\":12},	 {\"y\":7, \"x\":510, \"l\":14},	 {\"y\":8, \"x\":509, \"l\":16},     {\"y\":9, \"x\":507, \"l\":19}  ], \"target_area\": [     {\"y\":10, \"x\":517, \"l\":2},	 {\"y\":22, \"x\":510, \"l\":2}   ]  },  {\"bead_id\": 1,   \"bead_code\": 2340,   \"mirror\":0,   \"bead_area_count\":37,   \"target_area_count\":14,   \"bead_area\": [	 {\"y\":21, \"x\":1234, \"l\":2},	 {\"y\":22, \"x\":1232, \"l\":4},	 {\"y\":23, \"x\":1230, \"l\":7}  ],   \"target_area\": [     {\"y\":36, \"x\":1215, \"l\":2},	 {\"y\":37, \"x\":1213, \"l\":4}   ]  }]}

#include "stdafx.h"
#include "include\json\json.h"
#include <string>
#include <iostream>


void json_read()
{
	//std::string config_doc= "{\"moon\":\"rex\"}";
	std::string config_doc = "{\"file_name_TL\":\"E02_x1_y2_w0.tif\",\"file_name_FL_S\":\"E02_x1_y2_w1.tif\",\"file_name_FL_L\":\"E02_x1_y2_w2.tif\",\"processing_time\":312,\"beads\":[{\"bead_id\": 0,   \"bead_code\": 2340,   \"mirror\":1,   \"bead_area_count\":42,   \"target_area_count\":13,   \"bead_area\": [     {\"x\":517,\"y\":1,\"l\":2},	 {\"y\":2, \"x\":515, \"l\":4},	 {\"y\":3, \"x\":514, \"l\":6},	 {\"y\":4, \"x\":513, \"l\":8},	 {\"y\":5, \"x\":512, \"l\":10},	 {\"y\":6, \"x\":511, \"l\":12},	 {\"y\":7, \"x\":510, \"l\":14},	 {\"y\":8, \"x\":509, \"l\":16},     {\"y\":9, \"x\":507, \"l\":19}  ], \"target_area\": [     {\"y\":10, \"x\":517, \"l\":2},	 {\"y\":22, \"x\":510, \"l\":2}   ]  },  {\"bead_id\": 1,   \"bead_code\": 2340,   \"mirror\":0,   \"bead_area_count\":37,   \"target_area_count\":14,   \"bead_area\": [	 {\"y\":21, \"x\":1234, \"l\":2},	 {\"y\":22, \"x\":1232, \"l\":4},	 {\"y\":23, \"x\":1230, \"l\":7}  ],   \"target_area\": [     {\"y\":36, \"x\":1215, \"l\":2},	 {\"y\":37, \"x\":1213, \"l\":4}   ]  }]}";
	Json::Value root;
	Json::Reader reader;
	bool parsingSuccessful = reader.parse(config_doc,root);
	if (!parsingSuccessful) {std::cout << "Error" << reader.getFormattedErrorMessages(); }
	//std::string mon = root.get("moon","no-moon").asString();
	//std::cout << "moon:" << mon << std::endl;
	std::cout << root;
}

void json_write()
{
	Json::Value root;
	root["file_name_TL"] = "E02_x1_y2_w0.tif";
	root["file_name_FL_S"] = "E02_x1_y2_w1.tif";
	root["file_name_FL_L"] = "E02_x1_y2_w2.tif";
	root["processing_time"] = 312;
	for (int i=0; i<2; i++){
		Json::Value bead;
		Json::Value bead_area;
		Json::Value target_area;
		for (int j=0,x=517,y=1; j<10;j++){Json::Value bead_point; bead_point["x"] = x+j; bead_point["y"] = y+j; bead_point["l"] = j+1; bead_area.append(bead_point);}
		for (int j=0,x=517,y=1; j<4;j++){Json::Value target_point; target_point["x"] = x+j; target_point["y"] = y+j; target_point["l"] = j+1; target_area.append(target_point);}
		bead["bead_id"]=i;
		bead["bead_code"]=int((i+1)*10/3);
		bead["mirror"]=i;
		bead["bead_area_count"]=10;
		bead["target_area_count"]=4;
		bead["bead_area"] = bead_area;
		bead["target_area"] = target_area;
		root["beads"].append(bead);
	}
	//bead_point["x"] = 517;bead_area["y"] = 1; bead_area["l"] = 2;
	//bead_area["x"] = 517;bead_area["y"] = 1; bead_area["l"] = 2;
	//root["beads"].append
	std::cout << root;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	json_write();
	printf("Hi World!");
	getchar();
	return 0;
}

