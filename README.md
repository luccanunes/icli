# ICLI
 a c++ instagram cli

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
| `is_private`                          | is that profile private (`bool`) |
| `is_verified`                         | is that profile verified (`bool`) |
| `is_business_account`                 | is that profile a business account (`bool`) |
| `business_category_name`              | user's business category name (`std:string`) |
| `business_email`                      | user's business email (`std:string`) |
| `is_joined_recently`                  | was that profile created recently (`bool`) |
| `profile_pic_url_hd`                  | profile image URL (`std:string`) |

> If a data field does not apply to the user, the API returns `null`. <br /> For example, since `icli luccanunes is_business_account` returns `false`, `icli luccanunes business_email` returns `null`
