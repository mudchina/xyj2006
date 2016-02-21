//Cracked by Roath
// ajax  06/14/99

inherit ITEM;


string *names = ({
  "水草",
  "破靴子",
  "烂泥",
  "螃蟹壳",
});

string *units = ({
  "把",
  "只",
  "团",
  "个",
});


void create()
{
   int i;
   i=random(sizeof(names));
   set_name(names[i], ({"fei pin"}));
   set("unit", units[i]);
   set_weight(100);
   if( clonep() )
           set_default_object(__FILE__);
   else 
     {
     set("long","一堆沉在水底多年的废物。\n");
     }
   setup();
}


