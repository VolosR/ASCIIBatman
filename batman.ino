#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

const char image[] PROGMEM =
"                                                     \
                                                     \
                                                     \
                @       @    @        @              \
           @@@@@        @@@@@@        &@@@#          \
        @@@@@@@         @@@@@@         @@@@@@@       \
     ,@@@@@@@@@         @@@@@@         @@@@@@@@@     \
    @@@@@@@@@@@%       @@@@@@@@       @@@@@@@@@@@@   \
  #@@@@@@@@@@@@@@@   @@@@@@@@@@@@   @@@@@@@@@@@@@@@% \
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \
   @@@@@@@     %@@@    @@@@@@@%    @@@*     @@@@@@*  \
     @@@@,               @@@@               @@@@@    \
       @@@               (@@                @@@      \
          @               @@               @         \
                                                     \
                                                     \
";


void setup() {
   tft.init();
   tft.fillScreen(TFT_BLACK);
   tft.setTextColor(0x264E,TFT_BLACK);
   tft.setRotation(1);
  
   tft.setCursor(0,0);
   tft.print(image);

   sprite.createSprite(320,170);
   

}
int length=0;
int color=0;
char chars[6]="%&@G8";

void draw()
{
sprite.fillSprite(TFT_BLACK);
sprite.setCursor(0,0);
length=strlen(image);

for(int i=0;i<length;i++)
if(image[i]!=' '){
   color=random(180,230);

  sprite.setTextColor( tft.color565(color, color, 0),TFT_BLACK);
sprite.print(chars[random(0,4)]);
}else
{
  color=random(10,90);

  sprite.setTextColor( tft.color565(color, color, color),TFT_BLACK);
  
sprite.print(random(0,9));
}



sprite.pushSprite(random(0,6),random(0,6));

}

void loop() {
  draw();
  delay(80);


}

