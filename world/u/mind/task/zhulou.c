inherit EQUIP;

void create()
{
  set_name("细条竹篓", ({ "zhu lou","zhulou","lou","basket"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "只");
    set("long", "这是一只漂亮的细条竹篓。如果你找到下面７样东西：
    1、锄头
    2、竹篮
    3、竹簸箕
    4、竹扫帚
    5、竹筐
    6、青竹筒
    7、饭盒
然后就可以为吴文村长购置(gouzhi)出一套村民劳动用的竹制物什。\n");
    set("value", 200);
  }
  set("armor_prop/armor", 1);
  set("armor_type", "basket");
  set("wear_msg", "$N提起细条竹篓，轻巧地背在身上。\n");
  set("unequip_msg", "$N将细条竹篓从背后卸下来，抱在怀里。\n");
}

void init()
{
  if(this_player()==environment())
  add_action("do_gouzhi","gouzhi");
}

int do_gouzhi()
{
int i,geng=0,jiding=0,dusi=0,zhugan=0,dongsun=0,shucai=0,caomei=0;
object wushi,me, *inv;
object geng1,jiding1,dusi1,zhugan1,dongsun1,shucai1,caomei1;
me = this_player();

inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "锄头") {geng = 1; geng1 = inv[i];}
                        if(inv[i]->query("name") == "竹篮") {jiding = 1; jiding1 = inv[i];}
                        if(inv[i]->query("name") == "竹簸箕") {dusi = 1; dusi1 = inv[i];}
                        if(inv[i]->query("name") == "竹筐") {zhugan = 1;  zhugan1 = inv[i];}
                        if(inv[i]->query("name") == "青竹筒") {dongsun = 1; dongsun1 = inv[i];}
                        if(inv[i]->query("name") == "竹扫帚") {shucai = 1; shucai1 = inv[i];}
                        if(inv[i]->query("name") == "饭盒") {caomei = 1; caomei1 = inv[i];}
                        
                        
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
        
        wushi = new("/d/city/obj/wushi");
        wushi->move(me);
message_vision("$N购置了一些干活的物什，放进竹筐！\n",this_player());
        
        destruct(this_object());

}
else 
message_vision("$N简直象个纨绔子弟，搞不清楚这些东西有啥用．\n",this_player());

return 1;
}

