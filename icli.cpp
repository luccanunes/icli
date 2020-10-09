#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using namespace std;

bool cointains(vector<string> container, string item);

int main(int argc, char* argv[])
{
	if (argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		vector<string> commands = {
			"icli {user} ---------- gets all info about that user",
			"icli {user} {info} --- gets that info about that user"
		};
		for (string cmd : commands)
			cout << cmd << endl;
		return 0;
	}
	if (argc > 3) {
		cout << "[91mToo many arguments.[0m" << endl;
		cout << "[33mTo get a list of commands, type icli --help or icli -h.[0m" << endl;
		return 0;
	}

	vector<string> info_fields = {
		"id", "full_name", "biography", "is_private", "is_verified", "is_business_account",
		"business_category_name", "business_email", "is_joined_recently", "profile_pic_url_hd"
	};

	string field;

	if (argc == 3) {
		field = argv[2];
		if (!cointains(info_fields, field) && field != "followed_by" && field != "follows") {
			cout << "[91mThe information you requested is unavailable or doesn't exist.[0m" << endl;
			cout << "[33mTo get a list of data fields, go to https://github.com/luccanunes/icli [0m" << endl;
			return 0;
		}
	}

	string user = argv[1];

	string URL = "https://www.instagram.com/" + user + "/?__a=1";
	cpr::Response res = cpr::Get(cpr::Url{ URL });
	nlohmann::json jdata;
	jdata = nlohmann::json::parse(res.text);

	nlohmann::json info = jdata["graphql"]["user"];

	if (argc == 2) {
		for (string info_field : info_fields)
			cout << info_field << ": " << info[info_field] << endl;
		cout << "followed by: " << info["edge_followed_by"]["count"] << endl;
		cout << "follows: " << info["edge_follow"]["count"] << endl;
		return 0;
	}

	if (field == "followed_by") {
		cout << info["edge_followed_by"]["count"] << endl;
	}
	else if (field == "follows") {
		cout << info["edge_follow"]["count"] << endl;
	}
	else {
		cout << info[field] << endl;
	}
	return 0;
}

bool cointains(vector<string> container, string item)
{
	return find(container.begin(), container.end(), item) != container.end();
}