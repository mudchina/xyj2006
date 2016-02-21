//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

void create()
{
    set_name("逍遥丹", ({ "xiaoyao dan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "丸");
            set("material", "stone");
            set("long", "一丸用来男女欢悦，达到极乐的逍遥丹.
            1、药方
            2、玉蒲团
            3、爆炒腰花
            4、百花酿
然后就可以用药方(baoguo)出一包—催情秘药—，这是金钗女的闺房私物。\n");
            set("owner_name","玉面公主");
                     set("owner_id","yumian gongzhu");
          }

    setup();
}




void init()
{
  if(this_player()==environment())
  add_action("do_baoguo","baoguo");
}

int do_baoguo()
{
int i,geng=0,jiding=0,dusi=0,niang=0;
object shengsibu,me, *inv;
object geng1,jiding1,dusi1,niang1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "药方") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "玉蒲团") {jiding = 1; jiding1 = inv[i];}
                        if(inv[i]->query("name") == "爆炒腰花") {dusi = 1; dusi1 = inv[i];}
                        if(inv[i]->query("name") == "百花酿") {niang = 1; niang1 = inv[i];}
                        
                        }
if( geng && jiding && dusi && niang)
{
        destruct(geng1);
        destruct(jiding1);
        destruct(dusi1);
        destruct(niang1);
        shengsibu = new("/d/city/obj/shengsibu");
        shengsibu->move(me);
message_vision("$N把几样东西放在药方上，仔仔细细地包裹好！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N看着这些东西面红耳赤．\n",this_player());

return 1;
}
