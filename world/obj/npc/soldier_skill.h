
// let soldier's skill goes up with ppl's special spells
// me: the player who calls the soldier
// skill: the special spells that counts. e.g. moonshentong for heaven_soldier
// attack_skill: the attacking skill the soldier using
// e.g. sword for heaven_soldier, staff for putuo jingang

void give_skill(object me, string skill, string attack_skill) {

  int lvl;
  if (!me || !skill) return;
  lvl=me->query_skill(skill,1);
  if (lvl<100) return;

  set_skill(attack_skill,lvl);
  set_skill("parry",lvl);
  set_skill("dodge",lvl);
}
