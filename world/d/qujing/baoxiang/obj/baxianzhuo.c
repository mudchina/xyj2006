// by mind
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(RED"镂空红木八仙桌"NOR, ({"baxian zhuo", "zhuo", "table"}));
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一张镂空红木八仙桌，如果你找到下面１５样东西：
    1、桂花雪莲羹
    2、宫保鸡丁
    3、麻辣肚丝
    4、嫩汆猪肝
    5、麝香冬笋
    6、时鲜蔬菜
    7、草莓
    8、醉泥螺
    9、蒸螃蟹
    10、琼瑶豆腐
    11、野蘑菇
    12、银酒壶
    13、瓷酒盅
    14、香油馍馍
    15、红烧茯苓猪
然后就可以整置(zhengzhi)出一桌团圆宴席。\n");
    set("material", "wood");
    set("unit", "张");
    set("value", 1200);
  }
  setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_zhengzhi","zhengzhi");
}

int do_zhengzhi()
{
int i,geng=0,jiding=0,dusi=0,zhugan=0,dongsun=0,shucai=0,caomei=0,niluo=0,pangxie=0,doufu=0,mogu=0,jiuhu=0,jiuzhong=0,fan=0,zhu=0;
object tuanyuanyanxi,me, *inv;
object geng1,jiding1,dusi1,zhugan1,dongsun1,shucai1,caomei1,niluo1,pangxie1,doufu1,mogu1,jiuhu1,jiuzhong1,fan1,zhu1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "桂花雪莲羹") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "宫保鸡丁") {jiding = 1; jiding1 = inv[i];}
                        if(inv[i]->query("name") == "麻辣肚丝") {dusi = 1; dusi1 = inv[i];}
                        if(inv[i]->query("name") == "嫩汆猪肝") {zhugan = 1;  zhugan1 = inv[i];}
                        if(inv[i]->query("name") == "麝香冬笋") {dongsun = 1; dongsun1 = inv[i];}
                        if(inv[i]->query("name") == "时鲜蔬菜") {shucai = 1; shucai1 = inv[i];}
                        if(inv[i]->query("name") == "草莓") {caomei = 1; caomei1 = inv[i];}
                        
                        if(inv[i]->query("name") == "醉泥螺") {niluo = 1; niluo1 = inv[i];}
                        if(inv[i]->query("name") == "琼瑶豆腐") {doufu = 1; doufu1 = inv[i];}
                        if(inv[i]->query("name") == "蒸螃蟹") {pangxie = 1; pangxie1 = inv[i];}
                        if(inv[i]->query("name") == "野蘑菇") {mogu = 1;  mogu1 = inv[i];}
                        if(inv[i]->query("name") == "银酒壶") {jiuhu = 1; jiuhu1 = inv[i];}
                        if(inv[i]->query("name") == "瓷酒盅") {jiuzhong = 1; jiuzhong1 = inv[i];}
                        if(inv[i]->query("name") == "香油馍馍") {fan = 1; fan1 = inv[i];}
                        if(inv[i]->query("name") == "红烧茯苓猪") {zhu = 1; zhu1 = inv[i];}

                }
if( geng && jiding && dusi && zhugan && dongsun && shucai && caomei && niluo && pangxie && doufu && mogu && jiuhu && jiuzhong && fan && zhu )
{
        destruct(geng1);
        destruct(jiding1);
        destruct(dusi1);
        destruct(zhugan1);
        destruct(dongsun1);
        destruct(shucai1);
        destruct(caomei1);
        destruct(niluo1);
        destruct(doufu1);
        destruct(pangxie1);
        destruct(mogu1);
        destruct(jiuhu1);
        destruct(jiuzhong1);
        destruct(fan1);
        destruct(zhu1);
        tuanyuanyanxi = new("/d/city/obj/tuanyuanyanxi");
        tuanyuanyanxi->move(me);
message_vision("$N把手里的几样菜在八仙桌上精心摆放了一下．又放上几双
筷子和些手巾，一桌团圆宴席弄好了！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N把手里的几样菜摆放了几下．\n",this_player());

return 1;
}

