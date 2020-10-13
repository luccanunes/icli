# icli
 A instagram API wrapper command line tool, made in C++
 
## Installation
To install icli, all you have to do is clone this repo and compile `icli.cpp`, or [download the executable directly](https://mega.nz/file/3FkiUCrY#xPukt0BvlLVs17hXJQx9rlBUFPYMV29g1iCnryg97AU) (recommended).

## Requirements
- If you chose to compile the .cpp file by your self, you'll need the following libraries:
   * cpr - used for making http requests
   * nlohmann-json - used for parsing JSON data into map-like structures

## Usage
After installing icli, you have to make sure you add it to your Path environment variable. <br />
The details on how to do this are platform specific, so I'll  teach you how to do it for Windows here, and include a link with the instructions for other systems.

### Windows
- First of all, open up the start menu and search for "My computer". <br />
- Right click on it, and choose "Properties". <br />
- Go to "Advanced system settings". <br />
- Make sure you're in the "Advanced" tab and click "Environment variables" <br />
- Now just look for "Path", click "Edit" and then "New". <br />
- Simply paste the directory you installed icli.

### [Linux](https://opensource.com/article/17/6/set-path-linux)

### [Mac](https://www.cyberciti.biz/faq/appleosx-bash-unix-change-set-path-environment-variable/)

## Commands
|  Name                                 | Function |
| ------------------------------------- | -------- |
| `icli {username}`                     | gets all info about that user   |
| `icli {username} {info}`              | gets that specific info about that user   |

## Data fields
|  Name                                 | Meaning |
| ------------------------------------- | ------- |
| `id`                                  | user id (`std::string`) |
| `full_name`                           | user's full name (`std::string`) |
| `biography`                           | user's profile description/biography (`std::string`) |
| `followed_by`                         | followers count (`int`) |
| `follows`                             | follow count (`int`) |
| `is_private`                          | is that profile private (`bool`) |
| `is_verified`                         | is that profile verified (`bool`) |
| `is_business_account`                 | is that profile a business account (`bool`) |
| `business_category_name`              | user's business category name (`std:string`) |
| `business_email`                      | user's business email (`std:string`) |
| `is_joined_recently`                  | was that profile created recently (`bool`) |
| `profile_pic_url_hd`                  | profile image URL (`std:string`) |

If a data field does not apply to the user, the API returns `null`. <br /> For example, since `icli luccanunes is_business_account` returns `false`, `icli luccanunes business_email` returns `null`
