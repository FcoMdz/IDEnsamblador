IF PI exp-bool PD THEN bloque ELSE bloque FI {

}

IF error exp-bool PD THEN bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta paréntesis de apertura";
	inicial = $$;
}
IF PI error PD THEN bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta expresión boleana";
	inicial = $$;
}
IF PI exp-bool error THEN bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta paréntesis de cierre";
	inicial = $$;
}
IF PI exp-bool PD error bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta THEN";
	inicial = $$;
}
IF PI exp-bool PD THEN error ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta bloque siguiente";
	inicial = $$;
}
IF PI exp-bool PD THEN bloque error bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta sentencia else";
	inicial = $$;
}
IF PI exp-bool PD THEN bloque ELSE error FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta bloque después de else";
	inicial = $$;
}
IF PI exp-bool PD THEN bloque ELSE bloque error {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta final de if";
	inicial = $$;
}


IF error PD THEN bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta paréntesis de inicio y expresión boleana";
	inicial = $$;
}
IF PI exp-bool error bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta paréntesis de termino y THEN";
	inicial = $$;
}
IF PI exp-bool PD THEN error bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta paréntesis de termino y THEN";
	inicial = $$;
}
IF error THEN bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta paréntesis de inicio, termino y expresión ";
	inicial = $$;
}
IF PI exp-bool PD error bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta THEN, ELSE y bloque";
	inicial = $$;
}


IF PI error bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta expresión boleana, THEN, ELSE y bloque";
	inicial = $$;
}
IF PI exp-bool error ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta parentesis de cierre, THEN y bloque";
	inicial = $$;
}
IF PI exp-bool PD THEN error FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta bloque";
	inicial = $$;
}


IF error ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta bloque";
	inicial = $$;
}




IF PI error bloque FI {
std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta expresión, parentesis derecho, THEN";
	inicial = $$;
}
IF PI exp-bool error {
std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Parentesis derecho, THEN, bloque, FI";
	inicial = $$;
}


IF PI error FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Exoresión, Parentesis derecho, THEN, bloque";
	inicial = $$;
}



IF error bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Expresión, Parentesis derecho, THEN";
	inicial = $$;
}

IF PI error ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Expresión, Parentesis derecho, THEN, bloque";
	inicial = $$;
}
IF error bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Parentesis izquierdo, Expresión, Parentesis derecho, THEN";
	inicial = $$;
}
IF error exp-bool error THEN bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Exoresión, Parentesis derecho, THEN";
	inicial = $$;
}
IF error exp-bool error THEN bloque ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Exoresión, Parentesis derecho, THEN";
	inicial = $$;
}
IF error exp-bool error THEN error ELSE bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Parentesis izquierdo, Parentesis derecho, bloque";
	inicial = $$;
}
IF error exp-bool error THEN bloque error bloque FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Parentesis izquierdo, Parentesis derecho, ELSE";
	inicial = $$;
}
IF error exp-bool error THEN bloque ELSE error FI {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Parentesis izquierdo, Parentesis derecho, bloque";
	inicial = $$;
}
IF error exp-bool error THEN bloque ELSE bloque error {
	std::cout << "Error if\n";
	$$ = new struct Nodo;
	$$->nombre = "Error sintactico";
	$$->valor = "if falta Parentesis izquierdo, Parentesis derecho, FI";
	inicial = $$;
}
/* Marcó error
| IF PI exp-bool PD THEN bloque ELSE bloque error {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta final de if";
            inicial = $$;
        }
		*/