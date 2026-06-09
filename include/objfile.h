/* ============================================================================
 * objfile.h  
 *
 * Responsabilidad (Lair):
 * ==========================================================================*/
#ifndef IA32_OBJFILE_H
#define IA32_OBJFILE_H

#include <stddef.h>
#include "types.h"
#include "util.h"
#include "symtab.h"

/* Una relocacion final, tal como se guarda en el .o. */
typedef struct {
    SectionId section;    
    long      offset;        
    char      sym[MAXNAME];  
    RelocKind kind;        
    long      addend;      
} Reloc;


typedef struct {
    ByteBuf text;          
    ByteBuf data;           
    long    bss_size;      
    SectionId cur;           /* seccion actual durante el ensamblado          */

    long    org[SEC_COUNT];  

    SymTab *symtab;        

    Reloc  *relocs;
    size_t  nreloc, reloc_cap;

    char    srcname[256];  
} ObjModule;

void obj_module_init(ObjModule *m, SymTab *st);
void obj_module_free(ObjModule *m);
void obj_add_reloc  (ObjModule *m, SectionId sec, long off,
                     const char *sym, RelocKind kind, long addend);
long obj_section_len(const ObjModule *m, SectionId s);


int  obj_write(const char *path, ObjModule *m);


typedef struct {
    char    name[256];
    long    sec_size[SEC_COUNT];
    ByteBuf sec_bytes[SEC_COUNT];   

    Symbol *syms;  size_t nsyms,  sym_cap;
    Reloc  *relocs; size_t nreloc, reloc_cap;
} ObjFile;

int  obj_read(const char *path, ObjFile *o);  
void objfile_free(ObjFile *o);


void dump_symbols   (const char *path, SymTab *t);
void dump_sections  (const char *path, const ObjModule *m);
void dump_relocations(const char *path, const ObjModule *m);

#endif 
