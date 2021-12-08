#include <idc.idc>
static main(){
  //Finding jumps with the same target
  auto addr, prev_inst, curr_inst, prev_mnem, curr_mnem, prev_opnd, curr_opnd;
  addr = 0;
  prev_inst = FindCode(addr, SEARCH_DOWN | SEARCH_NEXT);
  curr_inst = FindCode(prev_inst, SEARCH_DOWN | SEARCH_NEXT);
  while(curr_inst != -1){
    prev_mnem = GetMnem(prev_inst);
    curr_mnem = GetMnem(curr_inst);
    if (prev_mnem == "jz" && curr_mnem == "jnz"){
      prev_opnd = GetOpnd(prev_inst, 0);
      curr_opnd = GetOpnd(curr_inst, 0);
      if (prev_opnd == curr_opnd){
        set_color(prev_inst, CIC_ITEM, 0xFFFF00);
        set_color(curr_inst, CIC_ITEM, 0xFFFF00);
      }
    }
    prev_inst = curr_inst;
    curr_inst = FindCode(curr_inst, SEARCH_DOWN | SEARCH_NEXT);
  }
}
