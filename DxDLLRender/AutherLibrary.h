#pragma once
struct  User
{
	std::string key;
	bool server = false;
	std::string name;
	std::string product;
	std::string detection;
	std::string status = xorstr("Waiting for input");
	std::string hwid = xorstr("authorizate first");
	std::string date = xorstr("authorizate first");
};
bool store_data;
bool restore_data;
static char buf2[17]; //измените длину ключа, 17 - 16 символов, 33 - 32 символа --> CHANGE THIS

User user;
//static char buf2[17]; //измените длину ключа, 17 - 16 символов, 33 - 32 символа --> CHANGE THIS
namespace AutherLibrary
{
	void Initialize(std::string kPublic, std::string kPrivate);
	bool Auth(std::string key, std::string hwid);
	bool CreateLog(std::string key, std::string message, std::string tag);
	std::string ExpireDateTimeStamp();
	std::string ExpireDateHumanReadable();
	std::string GetFullJsonResponse();
	std::string GetHwid();
}
std::string _pub = xorstr(""); //ваш публичный токен --> CHANGE THIS
std::string _priv = xorstr(""); //ваш приватный токен --> CHANGE THIS
namespace backend {

	void gathering_information()
	{
		user.hwid = AutherLibrary::GetHwid();
		user.date = AutherLibrary::ExpireDateHumanReadable();

		if (user.server)
			user.status = xorstr("Successfully authorized");
   }


void gathering_information()
{
	user.hwid = AutherLibrary::GetHwid();
	user.date = AutherLibrary::ExpireDateHumanReadable();

	if (user.server)
		user.status = xorstr("Successfully authorized");
}
void authorization()
{
	AutherLibrary::Initialize(_pub, _priv); //Почему оно здесь? Потому что ебучий гений на кодере сделал все настолько классно, что адрес токенов можно узнать в рантайме и просто хукнуть. Чтобы вашу чудо пасту не крякнули за 2 секунды, а уже за 5 я перенес её сюда.

	if (!restore_data) {
		user.key = buf2;
	}

	if (AutherLibrary::Auth(user.key.c_str(), AutherLibrary::GetHwid()))
	{
		user.server = true;
		gathering_information();
	}
	else
	{
		user.server = false;
		//user.status = xorstr("Incorrect key");
	}
