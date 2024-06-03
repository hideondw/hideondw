#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
int cache[128];
int num_hits = 0;
int num_miss = 0;



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	for(int i = 0; i < 128; ++i) cache[i] = -1;


}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte = address%32;
	unsigned int bloque_m = address/32; 
	unsigned int linea_mc = bloque_m%128;
	unsigned int tag = bloque_m/128;
	unsigned int miss = 0;
	unsigned int lec_mp = 0;
	unsigned int mida_lec_mp = 0;
	unsigned int esc_mp = 0;
	unsigned int mida_esc_mp = 0;
	unsigned int replacement = 0;
	unsigned int tag_out = 0;

	/* Escriu aqui el teu codi */
	if(LE == 0) {
		if(cache[linea_mc] != tag) {
			++num_miss;
			miss = 1;
			lec_mp = 1;
			if(cache[linea_mc] != -1) {
				replacement = 1;
				tag_out = cache[linea_mc];
			}
			mida_lec_mp = 32;
			cache[linea_mc] = tag; 
		}
		else ++num_hits;
	}
	else {
		esc_mp = 1;
		mida_esc_mp = 1;
		if(cache[linea_mc] != tag) {
			miss = 1;
			++num_miss;
		}
		else ++num_hits;
	}














	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
