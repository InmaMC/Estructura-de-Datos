/**
  * @file VectorDinamico.h
  * @brief Fichero cabecera del TDA VectorDinamico
  *
  * Se crea un vector con capacidad de crecer y decrecer
  * 
  */
#ifndef __VECTOR_DINAMICO
#define __VECTOR_DINAMICO


/**
 *  @brief T.D.A. VectorDinamico
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c VectorDinamico sobre el
 * tipo @c T es un array 1-dimensional de un determinado tama�o @e n, que
 * puede crecer y decrecer a petici�n del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]} 
 *
 * donde v[i] es el valor almacenado en la posici�n i del vector
 *
 * La eficiencia en espacio es @e O(n).
 */
template <class T>
class VectorDinamico {
  private:
    /**
      * @page repVectorDinamico Rep del TDA VectorDinamico
      *
      * @section invVectorDinamico Invariante de la representaci�n
      *
      * Un objeto v�lido @e v del TDA VectorDinamico debe cumplir 
      * - @c v.ocupados >= 0
      * - @c v.nelementos >= @c v.ocupados
      * - @c v.datos apunta a una zona de memoria con capacidad para albergar
      *   @c v.nelementos valores de tipo @c T
      *
      * @section faVectorDinamico  Funci�n de abstracci�n
      *
      * Un objeto v�lido @e rep del TDA VectorDinamico representa al vector de
      * tama�o @e nelementos, de los cuales @e ocupados elementos est�n en uso
      *
      * {v.datos[0],v.datos[1],...,v.datos[ocupados-1],...,v.datos[v.nelementos-1]}
      *
      */
    T * datos; /**< Apunta a los elementos del vector */
    int nelementos; /**< Indica el n�mero de elementos en @c datos */
		int ocupados; /**< Indica el n�mero de elementos en uso en @c datos */
  
  
  public:
  // ---------------  Constructores ----------------
  /**
    * @brief Constructor por defecto
    * @param n indica el n�mero de componentes inicial reservadas
    *   para el vector
    * @note
    *   Este constructor tambi�n corresponde al de por defecto
    */
    VectorDinamico(int n=0);
  
  /**
    * @brief Constructor de copia
    * @param c.datos vector de datos
    * @param c.nelementos n�mero de componentes inicial reservadas
    *   para el vector
    * @param c.ocupados n�mero de componentes inicial ocupadas
    *   en el vector  
    */
    VectorDinamico(const VectorDinamico<T> & original);

  // ------------------ Destructor ------------------
    ~VectorDinamico();

  // --------------- Otras funciones ---------------
  /**
    * @brief N�mero de componentes del vector
    * @return Devuelve el n�mero de componentes que puede almacenar en este
    * instante el vector
    * @see resize()
    */
    int getNelementos() const;

	/**
    * @brief N�mero de componentes en uso del vector
    * @return Devuelve el n�mero de componentes que est�n us�ndose en este
    * instante en el vector
    */
    int getOcupados() const;
  
  /**
    * @brief Comprueba si el vector est� vac�o
    */
    bool vacio() const;
  
  /**
    * @brief Comprueba si el vector est� lleno
    */
    bool lleno() const;

  /**
    * @brief Acceso a un elemento de un vector
    * @param i la posici�n del vector donde est� el componente
    * @pre 0<=i<getOcupados()
    * @return La referencia al elemento. Por tanto, se puede usar para almacenar
    *     un valor en esa posici�n.
    */
    T & operator[] (int i);

  /**
    * @brief Acceso a un elemento de un vector constante
    * @param i la posici�n del vector donde est� el componente
    * @pre 0<=i<getOcupados()
    * @return La referencia al elemento. Se supone que el vector no se puede
        modificar y por tanto es acceso de s�lo lectura
    */
    const T & operator[](int i) const;

  /**
    * @brief Redimensi�n del vector
    * @param n El nuevo tama�o del vector. n>=0
    * @post Los valores almacenados antes de la redimensi�n no se pierden
    *  (excepto los que se salen del nuevo rango de �ndices)
    */
    void resize(int n);
    
  /**
    * @brief Operador de asignaci�n
    * @param c.datos vector de datos
    * @param c.nelementos n�mero de componentes inicial reservadas
    *   para el vector
    * @param c.ocupados n�mero de componentes inicial ocupadas
    *   en el vector  
    */
    VectorDinamico & operator=(const VectorDinamico<T> & original);
  
  /**
    * @brief A�ade un nuevo elemento
    * @param nuevo el nuevo elemento a a�adir
    * @param i la posici�n en la que se va a a�adir el nuevo elemento 
    *   (por defecto justo detr�s del �ltimo)
    * @pre 0<=i<=getOcupados()
    */ 
    void insertar(const T & nuevo, int i=getOcupados());

  /**
    * @brief Elimina un elemento
    * @param i la posici�n del elemento que se va a eliminar
    *   (por defecto el �ltimo)
    * @pre 0<=i<getOcupados()
    */ 
    void eliminar(int i=getOcupados()-1);
};

#include "VectorDinamico.cpp"
#endif /* __VECTOR_DINAMICO */

