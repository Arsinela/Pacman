#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <vector>
#include <sstream>
using namespace sf;

int N = 19, M = 24;
int size = 40;
int w = size * N;
int h = size * M;
float delay;
int napr;
int  dir, playerLife, playerScore;
int mas[19][22];

struct person
{
	int x, y;

}r1, b3, p2, pac, o4;



void labirint()
{
	int i, j;
	for ( i = 0; i < 19; i++)
	{
		if ((i == 0) || (i == 18))
			for ( j = 0; j < 22; j++)
			{
				if (j == 10) mas[i][j] = 2;
				else
				{
					mas[i][j] = 1;
				}
			}
		if ((i == 1) || (i == 17))
			for (j = 0; j < 22; j++)
			{
				if ((j == 7) || (j == 8) || (j == 9) || (j == 12) || (j == 13) || (j == 17)|| (j == 21) || (j == 11) || (j == 0))
					mas[i][j] = 1;
				else
					if (j == 10) mas[i][j] = 2;
					else
					{
						mas[i][j] = 0;
					}
			}
		if ((i == 2) || (i == 16))
		for (j = 0; j < 22; j++)
		{
			if ((j == 1) || (j == 4) || (j == 6) || (j == 14) || (j == 16) || (j == 17) || (j == 18) || (j == 20))
				mas[i][j] = 0;
			else
				if (j == 10) mas[i][j] = 2;
				else
				{
					mas[i][j] = 1;
				}
		}
		if ((i == 3) || (i == 15))
			for (j = 0; j < 22; j++)
		{
			if ((j == 1) || (j == 4) || (j == 6) || (j == 14) || (j == 18) || (j == 20))

				mas[i][j] = 0;
			else
				if (j == 10) mas[i][j] = 2;
				else
				{
					mas[i][j] = 1;
				}
		}
		if ((i == 4) || (i == 14))
			for (j = 0; j < 22; j++)
		{
			if ((j == 19) || (j == 0) || (j == 21))
				mas[i][j] = 1;
			else
			{
				mas[i][j] = 0;
			}
		}
		if ((i == 5) || (i == 13))
			for (j = 0; j < 22; j++)
		{
			if ((j == 1) || (j == 4) || (j == 14) || (j == 16) || (j == 20))
				mas[i][j] = 0;
			else
				if (j == 10) mas[i][j] = 2;
				else
				{
					mas[i][j] = 1;
				}
		}
		if ((i == 6) || (i == 12))
			for (j = 0; j < 22; j++)
		{
			if ((j == 1) || (j == 4) || (j == 14) || (j == 16) || (j == 20) || (j == 17) || (j == 18) || (j == 5) || (j == 6))
				mas[i][j] = 0;
			else
				if ((j == 10) || (j == 8) || (j == 9) || (j == 11) || (j == 12) || (j == 13)) mas[i][j] = 2;
				else
				{
					mas[i][j] = 1;
				}
		}
		if ((i == 7) || (i == 11))
			for (j = 0; j < 22; j++)
		{
			if ((j == 1) || (j == 4) || (j == 14) || (j == 16) || (j == 20) || (j == 18) || (j == 6))
				mas[i][j] = 0;
			else
				if ((j == 8) || (j == 12)) mas[i][j] = 2;
				else
				{
					mas[i][j] = 1;
				}
		}
		if ((i == 8) || (i == 10))
			for (j = 0; j < 22; j++)
		{
			if ((j == 0) || (j == 5)|| (j == 9) || (j == 11) || (j == 13) || (j == 17) || (j == 21))
				mas[i][j] = 1;
			else
				if ((j == 8) || (j == 12) || (j == 7) || (j == 10)) mas[i][j] = 2;
				else
				{
					mas[i][j] = 0;
				}
		}
		if (i == 9)
			for (j = 0; j < 22; j++)
		{
			if ((j == 4) || (j == 20))
				mas[i][j] = 0;
			else
				if ((j == 8) || (j == 12) || (j == 9) || (j == 10) || (j == 16)) mas[i][j] = 2;
				else
				{
					mas[i][j] = 1;
				}
		}
	}
		
}

void Cross(RenderWindow & window)
{
	Event e;
	while (window.pollEvent(e))
	{
		if (e.type == Event::Closed)
			window.close();
	}
}

int menuSpeed(RenderWindow & window)
{
	 dir = 4, playerLife = 3, playerScore = 0;
	 labirint();
	 pac.x = 9;
	 pac.y = 16;
	 r1.x = 9;
	 r1.y = 9;
	 p2.x = 9;
	 p2.y = 10;
	 b3.x = 8;
	 b3.y = 10;
	 o4.x = 10;
	 o4.y = 10;
	Texture menuSpeedTexture1, menuSpeedTexture3, menuSpeedTexture2, menuSpeedTexture4, t5;
	menuSpeedTexture1.loadFromFile("мин.png");
	menuSpeedTexture2.loadFromFile("сред.png");
	menuSpeedTexture3.loadFromFile("макс.png");
	menuSpeedTexture4.loadFromFile("вых.png");
	t5.loadFromFile("змеяааа.png");
	Sprite menuSpeed1(menuSpeedTexture1), menuSpeed2(menuSpeedTexture2), menuSpeed3(menuSpeedTexture3), menuSpeed4(menuSpeedTexture4), sprite5(t5);
	bool isMenu = 1;
	int menuNum = 0;
	playerLife = 3;
	playerScore = 0;
	
	menuSpeed1.setPosition(10, 30);
	menuSpeed2.setPosition(10, 90);
	menuSpeed3.setPosition(10, 150);
	menuSpeed4.setPosition(10, 210);

	while (isMenu)
	{
		menuSpeed1.setColor(Color::White);
		menuSpeed2.setColor(Color::White);
		menuSpeed3.setColor(Color::White);
		menuSpeed4.setColor(Color::White);
		menuNum = 0;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
				isMenu = false;
			}
		}

		window.clear(Color(129, 181, 221));

		if (IntRect(10, 30, 404, 46).contains(Mouse::getPosition(window))) { menuSpeed1.setColor(Color::Green); menuNum = 1; }
		if (IntRect(10, 90, 312, 46).contains(Mouse::getPosition(window))) { menuSpeed2.setColor(Color::Green); menuNum = 2; }
		if (IntRect(10, 150, 409, 46).contains(Mouse::getPosition(window))) { menuSpeed3.setColor(Color::Green); menuNum = 3; }
		if (IntRect(10, 210, 117, 46).contains(Mouse::getPosition(window))) { menuSpeed4.setColor(Color::Green); menuNum = 4; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				delay = 0.2;
				isMenu = false;
			}

			if (menuNum == 2)
			{
				delay = 0.1;
				isMenu = false;
			}

			if (menuNum == 3)
			{
				delay = 0.05;
				isMenu = false;
			}

			if (menuNum == 4)
			{
				window.close();
				isMenu = false;
			}
		}
		//window.draw(sprite5);
		window.draw(menuSpeed1);
		window.draw(menuSpeed2);
		window.draw(menuSpeed3);
		window.draw(menuSpeed4);
		window.display();
	}
	
}

void WriteTextEnd(int gameTime, RenderWindow &window, Sound shootK, int playerScore)
{
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text  text3("", font, 80), text4("", font, 20), text1("", font, 50), text2("", font, 50);
	text3.setStyle(sf::Text::Bold);
	int gameS, gameM;
	std::ostringstream gameTimeStringS, gameTimeStringM, playerScoreString;   
	gameM = gameTime / 60;
	gameS = gameTime % 60;
	gameTimeStringM << gameM;		
	gameTimeStringS << gameS;
	playerScoreString << playerScore;
	text3.setString("Конец игры!");
	text3.setPosition(w / 3 - 40, h / 65);

	text4.setString("(Чтобы выйти в МЕНЮ нажмите esc)");
	text4.setPosition(w / 3 - 15 , 450);

	text1.setString("Время игры: " + gameTimeStringM.str()  + " мин " + gameTimeStringS.str() + " c");
	text1.setPosition(180, 200);

	text2.setString("Набрано очков: " + playerScoreString.str());
	text2.setPosition(240, 280);
	
	window.clear(Color(129, 181, 221));

	shootK.play();
	shootK.setLoop(true);
	window.draw(text3);
	window.draw(text4);
	window.draw(text1);
	window.draw(text2);
	window.display();
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
	shootK.stop();
	Event e;
	while (window.pollEvent(e))
	{
		if (e.type == Event::Closed)
		{
			window.close();
			
		}
	}
	menuSpeed(window);
}

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(w, h), "PACMAN");

	Font font;//шрифт
	font.loadFromFile("CyrilicOld.ttf");
	Text  text1("", font, 40), text2("", font, 40);
	
	menuSpeed(window);
	
	Texture t1, t2, tr, tl, tu, td, t4, t5, t6, t7;
	t1.loadFromFile("green2.png");
	t2.loadFromFile("white.png");
	tr.loadFromFile("pacRIGHT.png");
	tl.loadFromFile("pacLEFT.png");
	tu.loadFromFile("pacUP.png");
	td.loadFromFile("pacDOWN.png");
	t4.loadFromFile("redp.png");
	t5.loadFromFile("rozp.png");
	t6.loadFromFile("golp.png");
	t7.loadFromFile("orp.png");
	Sprite sten(t1), toch(t2), pacmanR(tr), pacmanU(tu), pacmanL(tl), pacmanD(td), rp1(t4), pp2(t5), pb3(t6), po4(t7);
	
	SoundBuffer shootBufferK;
	shootBufferK.loadFromFile("end.ogg");
	Sound shootK(shootBufferK);

	Clock clock;
	Clock gameTimeClock;
	int gameTime = 0, gameH, gameM;
	float timer = 0;

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			menuSpeed(window);
		}
		float time = clock.getElapsedTime().asSeconds();
		if (playerLife > 0)
		{
			gameTime = gameTimeClock.getElapsedTime().asSeconds();
		}
		clock.restart();
		timer += time;

		if (Keyboard::isKeyPressed(Keyboard::Left)) dir = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right))  dir = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up)) dir = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) dir = 0;

		if (timer>delay) 
		{ 
			timer = 0; 
	
			int i, j;
			i = pac.x;
			j = pac.y;

			if (dir == 0)
			{
				j += 1;
				if (mas[i][j] != 1)
					pac.y += 1;
				else
				{
					dir = napr;
				}
				if (mas[i][j] == 0)
				{
					mas[i][j] = 2;
					playerScore += 1;
				}
				napr = dir;
			}

			if (dir == 1)
			{
				i -= 1;
				if (mas[i][j] != 1)
					pac.x -= 1;
				else
				{
					dir = napr;
				}
				if (mas[i][j] == 0)
				{
					mas[i][j] = 2;
					playerScore += 1;
				}
				napr = dir;
			}
			if (dir == 2)
			{
				i += 1;
				if (mas[i][j] != 1)
					pac.x += 1;
				else
				{
					dir = napr;
				}
				if (mas[i][j] == 0)
				{
					mas[i][j] = 2;
					playerScore += 1;
				}
				napr = dir;
			}
			if (dir == 3)
			{
				j -= 1;
				if (mas[i][j] != 1)
					pac.y -= 1;
				else
				{
					dir = napr;
				}
				if (mas[i][j] == 0)
				{
					mas[i][j] = 2;
					playerScore += 1;
				}
				napr = dir;
			}
			if (pac.x > N)
				pac.x = 0;
			if  (pac.x < 0 )
				pac.x = N;
			
			if ((pac.x == r1.x) && (pac.y == r1.y) || (pac.x == p2.x) && (pac.y == p2.y) || (pac.x == b3.x) && (pac.y == b3.y) || (pac.x == o4.x) && (pac.y == o4.y))
			{
				playerLife -= 1;
			}
		}
			
		std::ostringstream playerScoreString, playerLifeString;   
		playerScoreString << playerScore;
		playerLifeString << playerLife;
		text1.setString("Набрано очков:" + playerScoreString.str());
		text1.setPosition(3, 875);

		text2.setString("Количество жизней:" + playerLifeString.str());
		text2.setPosition(355, 875);

		window.clear();

		for (int i = 0; i<N; i++)
			for (int j = 0; j<M-2; j++)
			{
				if (mas[i][j] == 1)
				{
					sten.setPosition(i*size, j*size);
					window.draw(sten);
				}
				if (mas[i][j] == 0)
				{
					toch.setPosition(i*size+16, j*size+16);
					window.draw(toch);
				}
				if (dir == 1)
				{
					pacmanL.setPosition(pac.x*size - 2, pac.y*size - 2);
					window.draw(pacmanL);
				}
				if (dir == 2)
				{
					pacmanR.setPosition(pac.x*size - 2, pac.y*size - 2);
					window.draw(pacmanR);
				}
				if (dir == 0)
				{
					pacmanD.setPosition(pac.x*size - 2, pac.y*size - 2);
					window.draw(pacmanD);
				}
				if (dir == 3)
				{
					pacmanU.setPosition(pac.x*size - 2, pac.y*size - 2);
					window.draw(pacmanU);
				}
				if (dir == 4)
				{
					pacmanL.setPosition(pac.x*size - 2, pac.y*size - 2);
					window.draw(pacmanL);
				}

				rp1.setPosition(r1.x*size-2, r1.y*size-2);
				window.draw(rp1);

				pp2.setPosition(p2.x*size - 2, p2.y*size - 2);
				window.draw(pp2);

				pb3.setPosition(b3.x*size - 2, b3.y*size - 2);
				window.draw(pb3);

				po4.setPosition(o4.x*size - 2, o4.y*size - 2);
				window.draw(po4);

				window.draw(text1);
				window.draw(text2);
				
				if (playerLife == 0)
				{
					WriteTextEnd(gameTime, window, shootK, playerScore);
				}
			}
		window.display();
		Cross(window);
	}
	return 0;
}

/*class Game
{
public:
Game() {}
Game(int X, int Y)
{
x = X;
y = Y;
}
~Game() {}
void SetX(int X)
{
x = X;
}
void SetY(int Y)
{
y = Y;
}
int GetX()
{
return x;
}
int GetY()
{
return y;
}
private:
int x;
int y;
};



void menuSpeed(RenderWindow & window)
{
Texture menuSpeedTexture1, menuSpeedTexture3, menuSpeedTexture2, menuSpeedTexture4, t5;
menuSpeedTexture1.loadFromFile("мин.png");
menuSpeedTexture2.loadFromFile("сред.png");
menuSpeedTexture3.loadFromFile("макс.png");
menuSpeedTexture4.loadFromFile("вых.png");
t5.loadFromFile("змеяааа.png");
Sprite menuSpeed1(menuSpeedTexture1), menuSpeed2(menuSpeedTexture2), menuSpeed3(menuSpeedTexture3), menuSpeed4(menuSpeedTexture4), sprite5(t5);
bool isMenu = 1;
int menuNum = 0;
playerLife = 3;
playerScore = 0;
num = 4;

menuSpeed1.setPosition(10, 30);
menuSpeed2.setPosition(10, 90);
menuSpeed3.setPosition(10, 150);
menuSpeed4.setPosition(10, 210);

while (isMenu)
{
menuSpeed1.setColor(Color::White);
menuSpeed2.setColor(Color::White);
menuSpeed3.setColor(Color::White);
menuSpeed4.setColor(Color::White);
sprite5.setPosition(441, 0);
menuNum = 0;

Cross(window);

window.clear(Color(193, 212, 85));

if (IntRect(10, 30, 404, 46).contains(Mouse::getPosition(window))) { menuSpeed1.setColor(Color::Green); menuNum = 1; }
if (IntRect(10, 90, 312, 46).contains(Mouse::getPosition(window))) { menuSpeed2.setColor(Color::Green); menuNum = 2; }
if (IntRect(10, 150, 409, 46).contains(Mouse::getPosition(window))) { menuSpeed3.setColor(Color::Green); menuNum = 3; }
if (IntRect(10, 210, 117, 46).contains(Mouse::getPosition(window))) { menuSpeed4.setColor(Color::Green); menuNum = 4; }

if (Mouse::isButtonPressed(Mouse::Left))
{
if (menuNum == 1)
{
delay = 0.2;
isMenu = false;
}

if (menuNum == 2)
{
delay = 0.1;
isMenu = false;
}

if (menuNum == 3)
{
delay = 0.05;
isMenu = false;
}

if (menuNum == 4)
{
window.close();
//isMenu = false;
}
}
window.draw(sprite5);
window.draw(menuSpeed1);
window.draw(menuSpeed2);
window.draw(menuSpeed3);
window.draw(menuSpeed4);
window.display();
}
}

void GoSnake(int dir, int num, Game *s)
{
for (int i = num; i > 0; --i)
{
s[i].SetX(s[i - 1].GetX());
s[i].SetY(s[i - 1].GetY());
}

if (dir == 0)
{
s[0].SetY(s[0].GetY() + 1);
}

if (dir == 1)
{
s[0].SetX(s[0].GetX() - 1);
}

if (dir == 2)
{
s[0].SetX(s[0].GetX() + 1);
}

if (dir == 3)
{
s[0].SetY(s[0].GetY() - 1);
}

if (s[0].GetX() > N - 1)
s[0].SetX(0);
if (s[0].GetX() < 0)
s[0].SetX(N - 1);
if (s[0].GetY() > M - 3)
s[0].SetY(0);
if (s[0].GetY() < 0)
s[0].SetY(M - 3);
}

void WriteTextGame(RenderWindow &window, int playerScore, int playerLife)
{
Font font;//шрифт
font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
Text  text1("", font, 20), text2("", font, 20);
text1.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
text2.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
std::ostringstream playerScoreString, playerLifeString;   // объявили переменную
playerScoreString << playerScore;
playerLifeString << playerLife;
text1.setString("Набрано очков:" + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
text1.setPosition(N - 15, 570);//задаем позицию текста, центр камеры

text2.setString("Количество жизней:" + playerLifeString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
text2.setPosition(N - 15, 540);

window.draw(text1);//рисую этот текст
window.draw(text2);//рисую этот текст
}

void WriteTextEnd(int gameTime, RenderWindow &window, Sound shootK, int playerScore)
{
Font font;//шрифт
font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
Text  text3("", font, 80), text4("", font, 20), text1("", font, 50), text2("", font, 50);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)																																   //text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый																															   //text5.setStyle(sf::Text::Bold);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
text3.setStyle(sf::Text::Bold);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
int gameS, gameM;
std::ostringstream gameTimeStringS, gameTimeStringM, playerScoreString;   // объявили переменную
gameM = gameTime / 60;
gameS = gameTime % 60;
gameTimeStringM << gameM;		//формируем строку
gameTimeStringS << gameS;
playerScoreString << playerScore;
text3.setString("Конец игры!");//задаем строку тексту и вызываем сформированную выше строку методом .str()
text3.setPosition(w / 3 - 40, h / 65);//задаем позицию текста, центр камеры

text4.setString("(Чтобы выйти в МЕНЮ нажмите esc)");//задаем строку тексту и вызываем сформированную выше строку методом .str()
text4.setPosition(w / 3, h - 48);//задаем позицию текста, центр камеры

text1.setString("Время игры: " + gameTimeStringM.str() + " мин " + gameTimeStringS.str() + " c");//задаем строку тексту и вызываем сформированную выше строку методом .str()
text1.setPosition(210, 200);//задаем позицию текста, центр камеры

text2.setString("Набрано очков: " + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
text2.setPosition(276, 280);//задаем позицию текста, центр камеры

shootK.play();//играем звук
shootK.setLoop(true);
window.draw(text3);//рисую этот текст
window.draw(text4);//рисую этот текст
window.draw(text1);//рисую этот текст
window.draw(text2);//рисую этот текст
window.display();
while (!Keyboard::isKeyPressed(Keyboard::Escape));
shootK.stop();
menuSpeed(window);//вызов меню
}

void WriteTextWin(RenderWindow &window, Sound shootK, int gameTime)
{
Font font;//шрифт
font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
Text  text("", font, 20), text1("", font, 100), text2("", font, 50);

int gameS, gameM;
std::ostringstream gameTimeStringS, gameTimeStringM, playerScoreString;   // объявили переменную
gameM = gameTime / 60;
gameS = gameTime % 60;
gameTimeStringM << gameM;		//формируем строку
gameTimeStringS << gameS;

text2.setString("Время игры: " + gameTimeStringM.str() + " мин " + gameTimeStringS.str() + " c");//задаем строку тексту и вызываем сформированную выше строку методом .str()
text2.setPosition(230, 230);//задаем позицию текста, центр камеры

text1.setString("Ты победил!");//задаем строку тексту и вызываем сформированную выше строку методом .str()
text1.setPosition(200, 100);//задаем позицию текста, центр камеры

text.setString("(Чтобы выйти в МЕНЮ нажмите esc)");//задаем строку тексту и вызываем сформированную выше строку методом .str()
text.setPosition(w / 3, h - 48);//задаем позицию текста, центр камеры

shootK.play();//играем звук
shootK.setLoop(true);
window.draw(text1);//рисую этот текст
window.draw(text);//рисую этот текст
window.draw(text2);//рисую этот текст
window.display();
while (!Keyboard::isKeyPressed(Keyboard::Escape));
shootK.stop();
menuSpeed(window);//вызов меню
}

void DrawSnake(int num, Sprite sprite2, Sprite sprite3, RenderWindow &window, Game *s)
{
for (int i = 1; i < num; i++)
{
sprite2.setPosition(s[0].GetX() * size, s[0].GetY() * size);
window.draw(sprite2);
sprite3.setPosition(s[i].GetX() * size, s[i].GetY() * size);
window.draw(sprite3);
}
}*/

//int d0 = 1, d1 = 0, d2 = 0, d3 = 0, RundFx, RundFy;

//menuSpeed(window);

/*Texture t1, t2, t3, t4;
t1.loadFromFile("зм.png");
t2.loadFromFile("перед змеи.png");
t3.loadFromFile("серед.png");
t4.loadFromFile("вишня.png");

SoundBuffer shootBuffer, shootBufferK, shootBufferY;//создаём буфер для звука
shootBuffer.loadFromFile("04535-[AudioTrimmer.com].ogg");//загружаем в него звук
shootBufferK.loadFromFile("end.ogg");//загружаем в него звук
shootBufferY.loadFromFile("упс.ogg");//загружаем в него звук

Sprite sprite1(t1), sprite2(t2), sprite3(t3), sprite4(t4);
Sound shoot(shootBuffer), shootK(shootBufferK), shootY(shootBufferY);//создаем звук и загружаем в него звук из буфера*/


/*Game f(10, 10);
Game s[35];
s[0].SetX(0);
s[0].SetY(0);*/


/*if ((Keyboard::isKeyPressed(Keyboard::Left)) && (d2 != 1))
{
dir = 1;
d1 = 1; d0 = 0; d3 = 0;
}
if ((Keyboard::isKeyPressed(Keyboard::Right)) && (d1 != 1))
{
dir = 2;
d2 = 1; d0 = 0; d3 = 0;
}
if ((Keyboard::isKeyPressed(Keyboard::Up)) && (d0 != 1))
{
dir = 3;
d3 = 1; d2 = 0; d1 = 0;
}
if ((Keyboard::isKeyPressed(Keyboard::Down)) && (d3 != 1))
{
dir = 0;
d0 = 1; d2 = 0; d1 = 0;
}

if (timer > delay)
{
timer = 0;
GoSnake(dir, num, s);

for (int i = 4; i < num; i++)
if (s[0].GetX() == s[i].GetX() && s[0].GetY() == s[i].GetY())
{
if (playerLife > 1)
{
shootY.play();//играем звук
}
playerScore = playerScore - (num - i);
--playerLife;
num = i;
}

if ((s[0].GetX() == f.GetX()) && (s[0].GetY() == f.GetY()))
{
shoot.play();//играем звук
num++;
playerScore++;
RundFx = rand() % N;
f.SetX(RundFx);
RundFy = rand() % M;
if ((RundFy != 20) && (RundFy != 19) && (RundFy != 18))
f.SetY(RundFy);
else
f.SetY(5);
}
}

window.clear();
window.draw(sprite1);

DrawSnake(num, sprite2, sprite3, window, s);

sprite4.setPosition(f.GetX()*size, f.GetY()*size);

window.draw(sprite4);

if ((playerLife > 0) && (num != 34))
{
WriteTextGame(window, playerScore, playerLife);
}
if (num == 34)
{
WriteTextWin(window, shootK, gameTime);
}
if (playerLife == 0)
{
WriteTextEnd(gameTime, window, shootK, playerScore);
}

window.display();

if (Keyboard::isKeyPressed(Keyboard::Escape))
{
menuSpeed(window);//вызов меню
}

Cross(window);*/