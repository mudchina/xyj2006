#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("风回雪舞剑", ({ "snowsword", "xue jian", "sword" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 700);
                set("material", "steel");
                set("long", "这是一把用来练舞的剑，剑身细长，轻巧尤锋利。如果你找到下面７样东西：
    1、神枪
    2、大斧
    3、鸳鸯棍
    4、凤尾鞭
    5、雁云刀
    6、八瓣梅花锤
    7、芦花草
然后就可以依样誊写(tengxie)出一张天下名器残谱。玉华老王爷正
千方百计想搞到手。\n");
                set("wield_msg", "$N抽出一把剑身细长的剑，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
                set("weapon_prop/courage", 4);
        }
        init_sword(40);
        setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_tengxie","tengxie");
}

int do_tengxie()
{
int i,geng=0,jiding=0,dusi=0,zhugan=0,dongsun=0,shucai=0,caomei=0;
object canpu,me, *inv;
object geng1,jiding1,dusi1,zhugan1,dongsun1,shucai1,caomei1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "神枪") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "大斧") {jiding = 1; jiding1 = inv[i];}
                        if(inv[i]->query("name") == "鸳鸯棍") {dusi = 1; dusi1 = inv[i];}
                        if(inv[i]->query("name") == "雁云刀") {zhugan = 1;  zhugan1 = inv[i];}
                        if(inv[i]->query("name") == "凤尾鞭") {dongsun = 1; dongsun1 = inv[i];}
                        if(inv[i]->query("name") == "八瓣梅花锤") {shucai = 1; shucai1 = inv[i];}
                        if(inv[i]->query("name") == "芦花草") {caomei = 1; caomei1 = inv[i];}
                        
                        
                }
if( geng && jiding && dusi && zhugan && dongsun && shucai && caomei)
{
        destruct(geng1);
        destruct(jiding1);
        destruct(dusi1);
        destruct(zhugan1);
        destruct(dongsun1);
        destruct(shucai1);
        destruct(caomei1);
        
        canpu = new("/d/city/obj/canpu");
        canpu->move(me);
message_vision("$N拿起小狼毫，一丝不苟地把这些神兵画下来，伪制了一张天下名器残谱！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N收获了这些利器，高兴地得意忘形。\n",this_player());

return 1;
}
