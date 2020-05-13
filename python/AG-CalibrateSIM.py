import numpy as np

## AG functions
class GA:
    def __init__(self, nindv, nger, pcross=.3, pmut=.1, ppred=.3, divty=5, minerr=0.001):
        """ Create instance of Genetic Algorithm
            Parameters:
            - nindv     : number of individuals in population
            - nger      : number of generation (stop criteria 1)
            - pcross    : percentage of crossover
            - pmut      : percentage of mutation
            - ppred     : percentage of predation (worst individuals will be killed)
            - divty     : diversity of predation application (each divth-th generation will apply predation)
            - conv      : minimum error of convergence (stop criteria 2)
        """
        self.nindv = nindv
        self.nger = nger
        self.pcross = pcross
        self.pmut = pmut
        self.ppred = ppred
        self.divty = divty
        self.minerr = minerr
    
    def setGAParameters(self, nindv, nger, pcross, pmut, ppred, divty, minerr):
        self.nindv = nindv
        self.nger = nger
        self.pcross = pcross
        self.pmut = pmut
        self.ppred = ppred
        self.divty = divty
        self.minerr = minerr

    def setPopulation(self, params, goal):
        """ setupPopulation(params, goal)
        - params    : range of each parameter as a list of possible values [[min_value, max_value]]
        - goal      : the output results that the GA will be achieve as a list of values
        """
        self.params = params
        # create new population
        self.population = np.array([])
        mpop = np.random.rand(self.nindv, len(params))
        mpop = params_minmax.T[0] + (mpop * (params.T[1] - params.T[0]))
        for i in mpop:
            self.pop


        # setup the goal to achieve
        self.goal = goal

    def runAG(self):
        for i in range(self.nger):
            # write parameters on simulation files
            # run simulations
            # obtain results from simulation
            # calculate fitness and rank individuals
            print(i)


vissim = GA(10, 100)
vissim.runAG()