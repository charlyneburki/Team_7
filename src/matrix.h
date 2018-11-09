/*!
 * This is a class modelising a matrix and the different calculations we can made with.
 */
class Matrix {
	private :
	// A pour la première colonne
	// C pour la deuxième colonne
	// G pour la troisième colonne
	// T pour la quatrième colonne
	vector < vector <double> > matrix;
	
	public:
	
	/*
	 * @brief constructeur qui initialise une matrice nulle
	 */
	Matrix();
	
	/*
	 * @brief constructeur qui initialise la matrice avec des valeurs
	 */
	Matrix(vector <vector <double> > m);
	
	/*
	 * @brief Pour modifier une composante de la matrice
	 * 
	 * @param x la ligne de la composante
	 * @param y la colonne de la composante
	 */
	void set_component(size_t x, size_t y, double poids);
	
	/*@brief calculer le score d'une séquence de nucléotides
	 * 
	 * @param la sequence dont on veut calculer le score
	 * 
	 * @return le score en double de la séquence
	 */
	double score_calculation(string sequence);
	
	/*
	 * @brief accéder à une composante de la matrice
	 * 
	 * @param x la ligne de la composante
	 * @param y la colonne de la composante
	 * 
	 * @return la valeur de la composante
	 */
	double get_component(size_t x, size_t y) const;
	
	/*
	 * @brief savoir si le score d'une séquence est au dessus d'un seuil donné
	 * 
	 * @param threshol le seuil limite
	 * @param la séquence dont on parle
	 * 
	 * @return true si on accepte la valeur et false sinon
	 */
	bool accept(double threshold, string sequence) const;
	
	
}
