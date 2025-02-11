# ParachuteModel

El presente programa implementa un modelo desarrollado en clase para evaluar la velocidad de un paracaidista que se deja caer de un punto fijo, suponiendo que la resistencia del viento es linealmente proporcional a la velocidad y actúa hacia arriba.

El primer modelo, un modelo exacto, es una ecuación diferencial que modela la relación entre la posición, masa del objeto o persona, gravedad terrestre y la resistencia del viento. En cambio, el segundo modelo resulta ser una función recursiva que obtiene la velocidad en un cierto momento con base en obtener las x velocidades anteriores con un paso dado.

Sin duda, la implementación del segundo modelo fue un reto dado que en búsqueda de ahorrar recursos en memoria y tiempo se optó por generar un bucle que llamara a la función no recursiva  que calcula la velocidad y guarda el valor anterior para calcular el siguiente.

Estos elementos en conjunto me enseñaron cómo es que se puede modelar un comportamiento físico de la vida real con programación. Desde comprender la física involucrada en el problema,  el proceso necesario para generar un modelo matemático, las ventajas y desventajas de los diferentes modelos que podemos crear, la implementación de cada modelo con sus respectivos retos y por último la comparación de resultados de cada uno.
