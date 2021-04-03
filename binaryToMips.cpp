#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <bits/stdc++.h> 

void rType(std::string);
void iType(std::string);
void jType(std::string);

std::string getRegister(std::string);
std::string getFunction(std::string);
std::string getImmOpcode(std::string);
std::string hexToBinary(std::string);
void printHex(std::string);

int main()
{
    bool mclength = true;
    std::string mc;

    while(mclength)
    {
        std::cout << "Enter a 32 bit MIPS hex code: \n0x";
        std::cin >> mc;



        if(mc.length() == 8)
        {
            mclength = false;
            
            //printHex(mc);
        }
        else
        {
            std::cout << "num was " << mc.length() << " bits" << std::endl;
        }       
    }

    mc = hexToBinary(mc);

    std::string opcode = mc.substr(0,6);

    std::cout << "Assembly Instruction: " << std::endl;
    if (opcode == "000000"){

        std::cout << "R type instruction" << std::endl;
        rType(mc);

    }
    else if (opcode == "001000") 
    {
        std::cout << "I type instruction" << std::endl;
        iType(mc);

    }
    else if (opcode == "000010")
    {
        std::cout << "J type instruction" << std::endl;
        jType(mc);
    }
    else
    {
        std::cout << "Opcode Not found" << std::endl;
    }
    return 0;
}

std::string hexToBinary(std::string hex)
{
    std::map<std::string, std::string> hexVals; 

    hexVals.insert(std::pair<std::string, std::string>("0", "0000")); 
    hexVals.insert(std::pair<std::string, std::string>("1", "0001")); 
    hexVals.insert(std::pair<std::string, std::string>("2", "0010")); 
    hexVals.insert(std::pair<std::string, std::string>("3", "0011")); 
    hexVals.insert(std::pair<std::string, std::string>("4", "0100")); 
    hexVals.insert(std::pair<std::string, std::string>("5", "0101")); 
    hexVals.insert(std::pair<std::string, std::string>("6", "0110")); 
    hexVals.insert(std::pair<std::string, std::string>("7", "0111")); 
    hexVals.insert(std::pair<std::string, std::string>("8", "1000")); 
    hexVals.insert(std::pair<std::string, std::string>("9", "1001")); 
    hexVals.insert(std::pair<std::string, std::string>("A", "1010")); 
    hexVals.insert(std::pair<std::string, std::string>("B", "1011")); 
    hexVals.insert(std::pair<std::string, std::string>("C", "1100")); 
    hexVals.insert(std::pair<std::string, std::string>("D", "1101")); 
    hexVals.insert(std::pair<std::string, std::string>("E", "1110")); 
    hexVals.insert(std::pair<std::string, std::string>("F", "1111"));

    std::string binary;

    for(int x = 0; x <= hex.length(); x++)
    {
        std::string place = std::to_string(x);
        binary = binary + hexVals[place];
    }

    std::cout << "Converted to binary: " +  binary << std::endl; 

    return binary;
}

void printHex(std::string mCode)
{
    std::map<std::string, std::string> hexVals; 

    hexVals.insert(std::pair<std::string, std::string>("0000", "0")); 
    hexVals.insert(std::pair<std::string, std::string>("0001", "1")); 
    hexVals.insert(std::pair<std::string, std::string>("0010", "2")); 
    hexVals.insert(std::pair<std::string, std::string>("0011", "3")); 
    hexVals.insert(std::pair<std::string, std::string>("0100", "4")); 
    hexVals.insert(std::pair<std::string, std::string>("0101", "5")); 
    hexVals.insert(std::pair<std::string, std::string>("0110", "6")); 
    hexVals.insert(std::pair<std::string, std::string>("0111", "7")); 
    hexVals.insert(std::pair<std::string, std::string>("1000", "8")); 
    hexVals.insert(std::pair<std::string, std::string>("1001", "9")); 
    hexVals.insert(std::pair<std::string, std::string>("1010", "A")); 
    hexVals.insert(std::pair<std::string, std::string>("1011", "B")); 
    hexVals.insert(std::pair<std::string, std::string>("1100", "C")); 
    hexVals.insert(std::pair<std::string, std::string>("1101", "D")); 
    hexVals.insert(std::pair<std::string, std::string>("1110", "E")); 
    hexVals.insert(std::pair<std::string, std::string>("1111", "F")); 

    std::cout << "Hex code converter" << std::endl;
    std::cout << mCode << std::endl;

    std::string x1 = hexVals[mCode.substr(0,4)];
    std::string x2 = hexVals[mCode.substr(4,4)];
    std::string x3 = hexVals[mCode.substr(8,4)];
    std::string x4 = hexVals[mCode.substr(12,4)];
    std::string x5 = hexVals[mCode.substr(16,4)];
    std::string x6 = hexVals[mCode.substr(20,4)];
    std::string x7 = hexVals[mCode.substr(24,4)];
    std::string x8 = hexVals[mCode.substr(28,4)];

    std::cout << "0x" << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << std::endl;
}


void rType(std::string mCode)
{
    std::cout << "rtyoeFunc" + mCode << std::endl;
    std::string opcode = getFunction(mCode.substr(0,6));

    std::cout << "opcode " + opcode << std::endl;

    std::string fn = getFunction(mCode.substr(25,6));
    //std::string sa = getShamt(mCode.substr(20,5));
    std::string rd = getRegister(mCode.substr(16,5));
    std::string rt = getRegister(mCode.substr(11,5));
    std::string rs = getRegister(mCode.substr(6,5));

    if(fn == "add" || fn == "addu" || fn == "and" || fn == "nor" || fn == "or" || fn == "slt" || fn == "sltu" || fn == "sub" || fn == "subu" || fn == "xor"){
        std::cout << fn << " " << rd << ", " << rs << ", " << rt << std::endl;
    }
    else if (fn == "break" || fn == "syscall")
    {
        std::cout << fn << std::endl;
    }
    else if (fn == "div" || fn == "divu" || fn == "mult" || fn == "multu")
    {
        std::cout << fn << " " << rs << ", " << rt << std::endl;
    }
    else if (fn == "div" || fn == "divu" || fn == "mult" || fn == "multu")
    {
        std::cout << fn << " " << rs << ", " << rt << std::endl;
    }
    else if (fn == "jr" || fn == "mthi" || fn == "mtlo" || fn == "multu")
    {
        std::cout << fn << " " << rs << std::endl;
    }
    else if (fn == "mfhi" || fn == "mflo")
    {
        std::cout << fn << " " << rd << std::endl;
    }
}

void iType(std::string mCode)
{
    std::string rt = getRegister(mCode.substr(11,5));
    std::string rs = getRegister(mCode.substr(6,5));
    std::string immOp = getImmOpcode(mCode.substr(0,6));

    int i_bin = std::stoi (mCode.substr(17,16),nullptr,2);

    std::cout << immOp << " " << rt << ", " << rs << ", " << i_bin << std::endl;
}

void jType(std::string mCode)
{
    int i_bin = std::stoi (mCode.substr(9,31),nullptr,2);
    std::cout << "jump: 0x" << i_bin << std::endl;
}


//
//00001011000011110000111100001111
//00100011000011110000111100001111
//
std::string getImmOpcode(std::string immOp)
{
    std::map<std::string, std::string> ops; 

    ops.insert(std::pair<std::string, std::string>("001000", "addi")); 
    ops.insert(std::pair<std::string, std::string>("001001", "addiu")); 
    ops.insert(std::pair<std::string, std::string>("001100", "andi")); 
    ops.insert(std::pair<std::string, std::string>("001101", "ori")); 
    ops.insert(std::pair<std::string, std::string>("001010", "slti")); 
    ops.insert(std::pair<std::string, std::string>("001011", "sltiu")); 
     
    if(ops[immOp] != "") return ops[immOp]; 
    
    return "imm op not found"; 
    
}

std::string getRegister(std::string reg)
{   
    std::map<std::string, std::string> registers; 

    registers.insert(std::pair<std::string, std::string>("00000", "$0")); 
    registers.insert(std::pair<std::string, std::string>("00001", "$at")); 
    registers.insert(std::pair<std::string, std::string>("00010", "$v0")); 
    registers.insert(std::pair<std::string, std::string>("00011", "$v1")); 
    registers.insert(std::pair<std::string, std::string>("00100", "$a0")); 
    registers.insert(std::pair<std::string, std::string>("00101", "$a1")); 
    registers.insert(std::pair<std::string, std::string>("00110", "$a2")); 
    registers.insert(std::pair<std::string, std::string>("00111", "$a3")); 
    registers.insert(std::pair<std::string, std::string>("01000", "$t0")); 
    registers.insert(std::pair<std::string, std::string>("01001", "$t1")); 
    registers.insert(std::pair<std::string, std::string>("01010", "$t2")); 
    registers.insert(std::pair<std::string, std::string>("01011", "$t3")); 
    registers.insert(std::pair<std::string, std::string>("01100", "$t4")); 
    registers.insert(std::pair<std::string, std::string>("01101", "$t5")); 
    registers.insert(std::pair<std::string, std::string>("01110", "$t6")); 
    registers.insert(std::pair<std::string, std::string>("01111", "$t7")); 
    registers.insert(std::pair<std::string, std::string>("10000", "$s0")); 
    registers.insert(std::pair<std::string, std::string>("10001", "$s1")); 
    registers.insert(std::pair<std::string, std::string>("10010", "$s2")); 
    registers.insert(std::pair<std::string, std::string>("10011", "$s3")); 
    registers.insert(std::pair<std::string, std::string>("10100", "$s4")); 
    registers.insert(std::pair<std::string, std::string>("10101", "$s5")); 
    registers.insert(std::pair<std::string, std::string>("10110", "$s6")); 
    registers.insert(std::pair<std::string, std::string>("10111", "$s7")); 
    registers.insert(std::pair<std::string, std::string>("11000", "$t8")); 
    registers.insert(std::pair<std::string, std::string>("11001", "$t9")); 
    registers.insert(std::pair<std::string, std::string>("11010", "$k0")); 
    registers.insert(std::pair<std::string, std::string>("11011", "$k1"));
    registers.insert(std::pair<std::string, std::string>("11100", "$gp")); 
    registers.insert(std::pair<std::string, std::string>("11101", "$sp")); 
    registers.insert(std::pair<std::string, std::string>("11110", "$fp")); 
    registers.insert(std::pair<std::string, std::string>("11111", "$ra")); 

    if(registers[reg] != "") return registers[reg];  
    
    return "reg not found";   
}

std::string getFunction(std::string func)
{
    std::map<std::string, std::string> funcs; 

    funcs.insert(std::pair<std::string, std::string>("100000", "add")); 
    funcs.insert(std::pair<std::string, std::string>("100001", "addu")); 
    funcs.insert(std::pair<std::string, std::string>("100100", "and")); 
    funcs.insert(std::pair<std::string, std::string>("001101", "break")); 
    funcs.insert(std::pair<std::string, std::string>("011010", "div")); 
    funcs.insert(std::pair<std::string, std::string>("100000", "divu")); 
    funcs.insert(std::pair<std::string, std::string>("100000", "jalr")); 
    funcs.insert(std::pair<std::string, std::string>("100000", "jr")); 
    funcs.insert(std::pair<std::string, std::string>("010000", "mfhi")); 
    funcs.insert(std::pair<std::string, std::string>("010010", "mflo")); 
    funcs.insert(std::pair<std::string, std::string>("010001", "mthi")); 
    funcs.insert(std::pair<std::string, std::string>("010011", "mtlo")); 
    funcs.insert(std::pair<std::string, std::string>("011000", "mult")); 
    funcs.insert(std::pair<std::string, std::string>("011001", "multu")); 
    funcs.insert(std::pair<std::string, std::string>("100111", "nor")); 
    funcs.insert(std::pair<std::string, std::string>("100101", "or")); 
    funcs.insert(std::pair<std::string, std::string>("000000", "sll")); 
    funcs.insert(std::pair<std::string, std::string>("000100", "sllv")); 
    funcs.insert(std::pair<std::string, std::string>("101010", "slt")); 
    funcs.insert(std::pair<std::string, std::string>("101011", "sltu")); 
    funcs.insert(std::pair<std::string, std::string>("000011", "sra")); 
    funcs.insert(std::pair<std::string, std::string>("000111", "srav")); 
    funcs.insert(std::pair<std::string, std::string>("000010", "srl")); 
    funcs.insert(std::pair<std::string, std::string>("000110", "srlv")); 
    funcs.insert(std::pair<std::string, std::string>("100010", "sub")); 
    funcs.insert(std::pair<std::string, std::string>("100011", "subu")); 
    funcs.insert(std::pair<std::string, std::string>("001100", "syscall	")); 
    funcs.insert(std::pair<std::string, std::string>("100110", "xor")); 

    if(funcs[func] != "") return funcs[func];  
    
    return "function not found"; 
}
