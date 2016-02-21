//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
void create()
{
        set_name("柳树枝", ({"liushu zhi", "shizhi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这可是具有法力的树枝!如果你找到下面２样东西：
    1、八卦云光帕
    2、混元金斗
然后就可以描绘(miaohui)出一张宝物图一。\n");
                set("unit", "条");
               set("owner_name","观音菩萨");
               set("owner_id","guanyin pusa");
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
object tuyi,me, *inv;
object geng1,jiding1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "八卦云光帕") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "混元金斗") {jiding = 1; jiding1 = inv[i];}
                        }
if( geng && jiding)
{
        destruct(geng1);
        destruct(jiding1);
        tuyi = new("/d/city/obj/tu_yi");
        tuyi->move(me);
message_vision("$N在宝物璀璨神光的照耀下，把这些宝物描了一张宝物图，做好记号“一”！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N摩挲着宝物，心旷神怡．\n",this_player());

return 1;
}

