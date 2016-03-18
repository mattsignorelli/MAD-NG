local M = {}

-- M.z1 = {{re=1, im=1}, {re=-1, im=1}, {re=1, im=-1}, {re=-1, im=-1}, {re=0, im=0}, {re=0, im=2}, {re=1, im=0}}

local pi, sin, cos = math.pi, math.sin, math.cos
local tnew = require 'table.new'

local N = 20

local function make_roots(n, scl)
  local roots = tnew(n,0)
  local angle

  for i=1,n do
    angle = (2*pi*(i-1))/n
    roots[i].re = cos(angle)*scl
    roots[i].im = sin(angle)*scl
  end

  return roots
end

M.unitroots  = make_roots(N * 4, 1)
M.sqrt2roots = make_roots(N * 4, math.sqrt(2))

M.expRef ={
  { re= 1.4686939399158852  , im= 2.2873552871788424  },
  { re= 0.19876611034641294 , im= 0.30955987565311220 },
  { re= 1.4686939399158852  , im=-2.2873552871788424  }, 
  { re= 0.19876611034641294 , im=-0.30955987565311220 },
  { re= 1.0000000000000000  , im= 0                   },
  { re=-0.41614683654714239 , im= 0.90929742682568170 },
  { re= 2.7182818284590452  , im= 0                   },
}

--[[
M.sinRef ={
  { re= 1.2984575814159773  , im= 0.6349639147847361 },
  { re=-1.2984575814159773  , im= 0.6349639147847361 }, 
  { re= 1.2984575814159773  , im=-0.6349639147847361 }, 
  { re=-1.2984575814159773  , im=-0.6349639147847361 },
  { re= 0                   , im= 0                  },
  { re= 0                   , im= 3.6268604078470188 },
  { re= 0.84147098480789651 , im= 0                  },
}

M.cosRef ={
  { 0.83373002513114905 , -0.98889770576286510 }, 
  { 0.83373002513114905 ,  0.98889770576286510 },
  { 0.83373002513114905 ,  0.98889770576286510 },
  { 0.83373002513114905 , -0.98889770576286510 }, 
  { 1.0000000000000000  ,  0                   },
  { 3.7621956910836315  ,  0                   }, 
  { 0.54030230586813972 ,  0                   }
}

--]]
return M
