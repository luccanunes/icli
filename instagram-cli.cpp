#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		vector<string> commands = {
			"icli {user} ---------- gets all info about that user",
			"icli {user} {info} --- gets that info about that user"
		};
		for (string cmd : commands)
			cout << cmd << endl;

		system("pause");
		return 0;
	}
	if (argc > 3) {
		cout << "Too many arguments." << endl;
		cout << "To get a list of commands, type icli --help or icli -h." << endl;
		system("pause");
		return 0;
	}

	string user = argv[1];

	string URL = "https://www.instagram.com/" + user + "/?__a=1";
	cpr::Response res = cpr::Get(cpr::Url{ URL });
	nlohmann::json jdata;
	jdata = nlohmann::json::parse(res.text);

	nlohmann::json info = jdata["graphql"]["user"];

	vector<string> info_fields = {
		"id", "full_name", "biography", "is_private", "is_verified", "is_business_account",
		"business_category_name", "is_joined_recently", "profile_pic_url_hd"
	};

	if (argc == 2) {
		for (string field : info_fields)
			cout << field << ": " << info[field] << endl;
		cout << "followed by: " << info["edge_followed_by"]["count"] << endl;
		cout << "follows: " << info["edge_follow"]["count"] << endl;

		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}