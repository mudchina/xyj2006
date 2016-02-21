// full.c

inherit F_CLEAN_UP;

int main(object ob,string arg)
{
        object me;
        int jin, qi, neili, fali, shiwu, yinshui;
     if (!arg)  me = ob;
     else
      {
        me = present(arg, environment(ob));
        if (!me) me =  find_player(arg);
        if (!me) return notify_fail("你要恢复谁的状态？\n");
      }
        jin = me->query("max_sen");
        qi =me->query("max_kee");
        fali = me->query("max_mana");
        neili = me->query("max_force");
        shiwu = me->max_food_capacity();
        yinshui = me->max_water_capacity();
        me->set("eff_sen", jin);
        me->set("eff_kee", qi);
        me->set("sen", jin);
        me->set("kee", qi);
        me->set("mana", fali);
        me->set("force", neili);
        me->set("food", shiwu);
        me->set("water", yinshui);
        write("Ok.\n");
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : full

此指令可让你恢复所有的精气。
HELP
    );
    return 1;
}
