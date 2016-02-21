//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

void create()
{
        set_name("金蛟剪", ({"jinjiao jian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "此剪乃是两条蛟龙，采天地灵气，受日月精华，起在空中，往来上下，\n祥云护体，头并头如剪，尾交尾如股；不怕你得道神仙，一插两段。\n如果你找到下面２样东西：
    1、火龙镖
    2、定海珠
然后就可以描绘(miaohui)出一张宝物图二。\n");
                set("unit", "件");
                set("lingtaibao","fake");
                 set("owner_name","菩提祖师");
                 set("owner_id","master puti");
        }
}

void init()
{
  if(this_player()==environment())
  add_action("do_miaohui","miaohui");
}

int do_miaohui()
{
int i,geng=0,jiding=0;
object tuer,me, *inv;
object geng1,jiding1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "火龙镖") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "定海珠") {jiding = 1; jiding1 = inv[i];}
                        }
if( geng && jiding)
{
        destruct(geng1);
        destruct(jiding1);
        tuer = new("/d/city/obj/tu_er");
        tuer->move(me);
message_vision("$N在宝物璀璨神光的照耀下，把这些宝物描了一张宝物图，做好记号“二”！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N摩挲着宝物，心旷神怡．\n",this_player());

return 1;
}
