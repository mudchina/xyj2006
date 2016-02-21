#include <armor.h>

#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name("鎏金腕链", ({ "liujin wanlian", "wanlian", "wrists" }));
  set("weight", 200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "如果你找到下面６样东西：
    1、软香鞋
    2、香囊
    3、花裙子
    4、凤冠
    5、玉佩
    6、钻石戒指
然后就可以为女儿国梅鸳鸯定制(dingzhi)一套嫁衣。\n");
    set("unit", "个");
    set("value", 5000);
    set("material", "gold");
    set("armor_prop/armor", 1);
  }
  setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_dingzhi","dingzhi");
}

int do_dingzhi()
{
int i,geng=0,jiding=0,dusi=0,zhugan=0,dongsun=0,shucai=0;
object jiayi,me, *inv;
object geng1,jiding1,dusi1,zhugan1,dongsun1,shucai1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == HIR"香囊"NOR) {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == RED"软香鞋"NOR) {jiding = 1; jiding1 = inv[i];}
                        if(inv[i]->query("name") == "花裙子") {dusi = 1; dusi1 = inv[i];}
                        if(inv[i]->query("name") == "凤冠") {zhugan = 1;  zhugan1 = inv[i];}
                        if(inv[i]->query("name") == "玉佩") {dongsun = 1; dongsun1 = inv[i];}
                        if(inv[i]->query("name") == "钻石戒指") {shucai = 1; shucai1 = inv[i];}
                        
                        
                        
                }
if( geng && jiding && dusi && zhugan && dongsun && shucai)
{
        destruct(geng1);
        destruct(jiding1);
        destruct(dusi1);
        destruct(zhugan1);
        destruct(dongsun1);
        destruct(shucai1);
        
        jiayi = new("/d/city/obj/jiayi");
        jiayi->move(me);
message_vision("$N有板有眼地把衣、裙、饰物等整理出一套嫁衣！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N闻了闻这些女儿家东西，觉得好香。\n",this_player());

return 1;
}
