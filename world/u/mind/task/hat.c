// /d/gao/obj/hat.c

#include <armor.h>

inherit HEAD;

void create()
{
        set_name("毡帽", ({ "hat" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                


        set("long", "一顶普通的帽子，如果你找到下面４样东西：
    1、虎皮帽
    2、黑丝帽
    3、牛皮帽
    4、傻帽
然后就可以置办(zhiban)出一套民间货帽，天竺的甜妞卖得十分红火。\n");
                set("unit", "顶");
                set("material", "cloth");
                set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_zhiban","zhiban");
}

int do_zhiban()
{
int i,geng=0,jiding=0,dusi=0,zhugan=0;
object minmao,me, *inv;
object geng1,jiding1,dusi1,zhugan1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "虎皮帽") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "黑丝帽") {jiding = 1; jiding1 = inv[i];}
                        if(inv[i]->query("name") == "牛皮帽") {dusi = 1; dusi1 = inv[i];}
                        if(inv[i]->query("name") == "傻帽") {zhugan = 1;  zhugan1 = inv[i];}
                        

                }
if( geng && jiding && dusi && zhugan)
{
        destruct(geng1);
        destruct(jiding1);
        destruct(dusi1);
        destruct(zhugan1);
        
        minmao = new("/d/city/obj/minmao");
        minmao->move(me);
message_vision("$N把这些帽子分类叠放在一起，置办了一套民间货帽！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N觉得这些帽子不但好看，而且有趣．\n",this_player());

return 1;
}
