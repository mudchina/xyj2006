//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

string *names = ({
  "[33mÀÏ»¢Èâ[m",
  "[31mÏãâ¯Èâ[m",
  "[32mòşÉßÈâ[m",
  "[33mºüÀêÈâ[m",
  "[34mÍÃÈâ[m",
  "[35mÂ¹Èâ[m",
});

string *ids = ({
    "laohu rou",
    "xiangzhang rou",
    "mangshe rou",
    "huli rou",
    "tu rou",
    "lu rou",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set_weight(80);
      if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿ìÏãÅçÅçµÄÑ¬Èâ¡£\n");
                set("unit", "¿é");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

