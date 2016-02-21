//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
void create()
{
        set_name("文书", ({"wen shu", "shu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "寂灭司主「阴王」阴长生的文书。如果你找到下面３样东西：
                1、绣花针
                2、滴天髓
                3、碎布头
然后就可以订(ding)出一本《阎王生死簿》，这是阎罗王的要紧物什。
灵山 金顶大仙超度成仙之人时候要写凭据。\n");
                set("unit", "件");
               set("owner_name","阴长生");
               set("owner_id","yin changsheng");
        }
}

void init()
{
  if(this_player()==environment())
  add_action("do_ding","ding");
}

int do_ding()
{
int i,geng=0,jiding=0,dusi=0;
object shengsibu,me, *inv;
object geng1,jiding1,dusi1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "绣花针") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "滴天髓") {jiding = 1; jiding1 = inv[i];}
                        if(inv[i]->query("name") == "碎布头") {dusi = 1; dusi1 = inv[i];}
                        
                        
                        }
if( geng && jiding && dusi)
{
        destruct(geng1);
        destruct(jiding1);
        destruct(dusi1);
        
        shengsibu = new("/d/city/obj/shengsibu");
        shengsibu->move(me);
message_vision("$N拈起绣花针，细心地修补好了《阎王生死簿》！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N弄不清楚这些东西有什么用途．\n",this_player());

return 1;
}
